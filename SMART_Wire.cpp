/*
  SMART_Wire.cpp - Library for controlling Shape Memory Alloy Wires using resistance tracking methods. 
  Created by Timothy Lobiak, March 10, 2020.
  Released into the public domain.
*/

/*

TASKS:
- rMin and rMax validation
- Study why resistance changes at cool state
- How does resistance change upon overheating? Does it increase a lot?
*/

#include "Arduino.h"
#include "DPM_8600.h"
#include "SMART_Wire.h"

SMART_Wire::SMART_Wire(float wireResistance, float recommendedCurrent, float resistanceDropThreshold, float X, float Y) : R(wireResistance), Rth(resistanceDropThreshold), _rC(recommendedCurrent), _errorNum(1)
{
    coeff[0] = X;
    coeff[1] = Y;
}

const float SMART_Wire::_rMin = 1.5;
const float SMART_Wire::_rMax = 60;

/// PUBLIC: 

int SMART_Wire::train(DPM_8600 &converter) 
{
    _converter = &converter;

    // Step 1. Check if resistance is given, otherwise, measure resistance.
    if (R == 0) {
        R = measureResistance();
        if (R <= 0) {
            // Failed measuring the resistance
            return (int)R;
        }
    }

    // Step 2. Check if resistance threshold is given, otherwise, measure it if recommended current is given. If none are given, use a default value.
    if (Rth == 0 && _rC != 0) {
        Rth = measureResistanceDrop();
        Rth = 0.5 * Rth; // At 50% of the original drop we should be fairly confident that the resistance drop is not just an error.
    } else {
        Rth = 0.07; // Works for most observed cases
    }

    if (_errorNum != 1) {
        return (int)_errorNum;
    }

    // Step 3. Determine X and Y coefficients
    if (coeff[0] == 0 && coeff[1] == 0) {
        measureCoefficients(coeff[0], coeff[1]);
    }

    // Step 4. Calculate max and min times and currents that can be applied
    calculateBoundaries();

    return (int)_errorNum;
}

int SMART_Wire::activate(float t)
{
    float c = currentFor(t);
    bool success = activateWith(c, t);
    return (success) ? 1 : (int)_errorNum;
}

int SMART_Wire::apply(float c, float t)
{
    float v = (R == 0) ? 60 : (c*R*1.25);

    _errorNum = _converter->writeVC(v, c);
    if (_errorNum != 1) {
        return _errorNum;
    }
    _converter->power(true);
    delay(floor(t*1000));
    _converter->power(false);

    return _errorNum;
}

float SMART_Wire::currentFor(float t)
{
    return sqrt((coeff[0] / t) + coeff[1]);
}

float SMART_Wire::timeFor(float c)
{
    return (coeff[0] / (sq(c) - coeff[1]));
}

/// PRIVATE: 

bool SMART_Wire::activateWith(float c, float &t) 
{
    float v = R * c * 1.25; // Multiplying by 1.25 to get voltage over what current could be, ensuring that it is CC.
    _errorNum = _converter->writeVC(v, c);

    if (_errorNum != 1) {
        return false;
    }

    // Set Initial Resistance
    float rinit = R;

    // Set Alternating Resistance to Initial
    float r = R;

    // Past value of r
    float rOld = R;

    // State of the resitance drop 
    // 0 - nothing happening
    // 1 - going down
    // 2 - going up
    int8_t change = 0;

    // State variable telling whether the wire finished activating
    bool finished = false;

    // State variable telling whether the wire passed the threshold Rth and started activating
    bool started = false;

    // Number of consequtive similar measurements
    int count = 0;

    // Change value
    float slope = 0;
  
    // Record Time Stamp
    unsigned long timeStamp = millis();

    // Turn on the power
    _converter->power(true);
  
    delay(600);
  
    // Measure voltage
    v = _converter->read('v');

    if (v < 0) {
        _errorNum = floor(v);
        _converter->power(false);
        return false;
    }
  
    // Run a while loop which will only be exited if time exceeds t+1 seconds or resistance drops low enough
    while ((!finished) && (millis() - timeStamp < ((t + 1) * 1000))) {
        // Step 1. Measure the voltage and calculate resistance
        v = _converter->read('v');
        r = (v / c);

        // Step 2. Check if the resistance passed the starting threshold
        if ((r < rinit * (1 - Rth)) && !started) {
            started = true;
        }

        // Step 3. If started calculate slope and change state.
        if (started) {
            slope = 1 - (r/rOld);
            if (slope > 0.005) {
                // Resistance decreasing. Change state and reset count
                change = 1;
                count = 0;
            } else if (slope < -0.005) {
                // Resistance is increasing. Change state and reset count only if wasn't already increasing.
                count = (change == 2) ? (count + 1): 0; 
                change = 2; 
            } else {
                // Resistance is not changing much, increment the count
                count += 1; 
            }
        }

        // Step 4. If the count reached a certain value exit the loop. The value is set for 10, that means that the loop would finish after 10*35 = 0.35s of no change
        if (count >= 10) {
            finished = true;
        }

        // Step 5. Ensure that rinit gets the max value, and the drop is counted from that value.
        if (r > rinit) {
            rinit = r;
        }

        // Step 6. Update previous resistance value
        rOld = r;

        // Step 7. Delay so that the loop doesn't run so fast
        delay(35);
    }
  
    // Turn off the power
    _converter->power(false);

    if (finished) {
        t = (float)(millis()-timeStamp) / 1000.0;
        return true;
    } else {
        return false;
    }
}

void SMART_Wire::measureCoefficients(float &x, float &y) 
{
    // Setting intial current to either recommendedCurrent if it is available or 200mA to start with.
    float c = (_rC == 0) ? 0.2 : _rC;
    float deltaT[2];
    float cVal[2];
    uint8_t successfulTestCount = 0;

    while (successfulTestCount < 2) {

        float t = 10;
        bool success = activateWith(c, t);

        if (success) {
            cVal[successfulTestCount] = c;
            deltaT[successfulTestCount] = t;
            c += (c*0.05 > 0.04) ? c*0.05 : 0.04; // 5% increment with minimum of 0.04A
            successfulTestCount++;
        } else {
            c += (c*0.1 > 0.1) ? c*0.1 : 0.1; // 10% increment, with minimum of 0.1A
        }

        if (_errorNum != 1) {
            break;
        }

        if (c >= 5) {
            _errorNum = -30;
            break;
        }
        
        delay((success ? 60000 : 40000)); // 1 min to cool down if success,  40 seconds otherwise
    }

    if (_errorNum != 1) {
        return ;
    }

    // Calculating constants I^2 = X/t + Y
    x = (sq(cVal[0]) - sq(cVal[1])) / ((1 / deltaT[0]) - (1 / deltaT[1]));
    y = sq(cVal[0]) - (y / deltaT[0]);

    
    // If x <= 0 there is certainly an error in measurements as it would mean less current needed for shorter time

    if (x <= 0) {
        _errorNum = -34;
    }

    return ;
}

float SMART_Wire::measureResistanceQuick()
{
    _converter->power(true);
    delay(1500);
    float c = _converter->read('c');
    float v = _converter->read('v');
    _converter->power(false);

    return v/c;
}

float SMART_Wire::measureResistance() 
{
    _errorNum = _converter->writeVC(5, 0.1);
    if (_errorNum != 1) {
        return _errorNum;
    }
    
    const int measurements = 6;
    float r = 0;
    float rArray[measurements];
    float rDevi[measurements];
    float rDeviAvg = 0;
    float rMean = 0;

    // Step 1. Collect measurements
    for (int i = 0; i < measurements; i++) {

        // Taking Measurements
        _converter->power(true);
        delay(1500);
        float c = _converter->read('c');
        float v = _converter->read('v');
        _converter->power(false);

        // Checking for Errors
        if (v < 0) {
            _errorNum = floor(v);
            break;
        } else if (c < 0) {
            _errorNum = floor(c);
            break;
        } else if (c < 0.01) {
            _errorNum = -33;
            break;
        }

        // Adding a data point
        rArray[i] = (v / c);
        rMean += (v / c) / measurements;
        
        delay(9000); // 1min for 6 measurements
    }

    if (_errorNum != 1) {
        return _errorNum;
    }
 
    // Step 2. Calculate mean value and a deviation for each measurement and calculate mean deviation
    for  (int i = 0; i < measurements; i++) {
        rDevi[i] = abs(rArray[i] - rMean);
        rDeviAvg += rDevi[i]/measurements;
    }

    // Step 3. Remove all values which have abnormal deviation compared to the average
    int k = 0;
    for (int i = 0; i < measurements; i++) {
        if (rDevi[i] <= 2*rDeviAvg) {
            k += 1;
            r += rArray[i];
        } 
    }

    // Step 4. Calculate the mean of the rest of the measurements
    r = r / k;

    // Step 5. Check if resistance is within the range
    if (r < _rMin) {
        return -31;
    } else if (r > _rMax) {
        return -32;
    }

    return r;
}

float SMART_Wire::measureResistanceDrop()
{
    float v = _rC * R * 1.25;

    _errorNum = _converter->writeVC(v, _rC);

    // Record Time Stamp
    unsigned long timeStamp = millis();

    // Turn on the power
    _converter->power(true);
    
    delay(5000);

    // Measure voltage after a 5s delay (usually recommended current is meant for 3s approx.) 
    v = _converter->read('v');

    float r;
    r = v/_rC;
    
     if (v < 0) {
        _errorNum = v;
        _converter->power(false);
        return _errorNum;
    }

    // Turn off the power
    _converter->power(false);

    return r/R;
}

void SMART_Wire::calculateBoundaries()
{
    cMin = currentFor(10);
    cMax = currentFor(1);
    tMin = 1;
    tMax = 10;
    if (cMin < 0.1) {
        tMax = timeFor(0.1);
        cMin = currentFor(tMax);
    }

    if (cMax > 5) {
        tMin = timeFor(5);
        cMax = currentFor(tMin);
    }
}