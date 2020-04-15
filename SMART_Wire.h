/*
  SMART_Wire.h - Library for controlling Shape Memory Alloy Wires using resistance tracking methods. 
  Created by Timothy Lobiak, March 10, 2020.
  Released into the public domain.

  --------------- METHODS ---------------

  - SMART_Wire(wireResistance, recommendedCurrent, resistanceDropThreshold, X, Y) - Constructor. Could be initialized as an empty constructor, thus training would be negligible
      * wireResistance [Ohm] - if the resistance of the wire is known
      * recommendedCurrent [A] - if the current that is recommeneded for that wire is known
      * resistanceDropThreshold [%]- if it is know how much the resistance of the wire changes when being heated.
      * X, Y - coefficients in the equation of I^2 = (X/time) + Y. Those variables could be provided or estimated.

  - train(converter) - Training function, which based on the variables provided in constructor finds the necessary parameters for activation. Returns error state
      * converter - DPM8600 converter. Over time support for other converter types would be available

  - apply(c, t) - A direct command to apply certain amount of current for a specific time. Recommeneded to have resistance measured or entered prior to that
      * c [A] - current that needed to be applied in max
      * t [seconds] - time for the current to be applied in seconds.

  - activate(t) - Activation function for the wire to be activated within given time. Returns error state.
      - t [seconds] - time for the wire to be activated within.
  
  - currentFor(t) - Conversion function which returns a float of the current [A] necessary for the wire to be activated within a certain amount of time [seconds]

  - timeFor(c) - Conversion function which returns a float of the time [seconds] the wire should be activated within under the given current [A]

  --------------- PUBLIC PARAMETERS ---------------

  - R - resistance of the wire
  - Rth - resistance drop of the wire
  - coeff[0] and coeff[1] - X and Y coefficients correspondingly 
  - cMin - minimum activation current
  - cMax - maximum activation current
  - tMin - shortest activation time
  - tMax - longest activation time

  --------------- ERRORS ---------------

  ONLY 1 is no error state, all the negative states mean errors.
  1 - NO ERROR
  -10 - error on voltage reading
  -11 - error on current reading
  -14 - error on max current reading
  -20 - wrong value sent to power writing function
  -21 - error setting current
  -22 - error setting power on/off
  -23 - error setting voltage
  -24 - error setting current and voltage
  -30 - maximum current reached upon tests
  -31 - resistance below minimum threshold
  -32 - resistance beyond maximum threshold
  -33 - open circuit or resistance too high for measurements
  -34 - errors during training.
*/

#ifndef SMART_Wire_h

#define SMART_Wire_h
#include "Arduino.h"
#include "DPM8600.h"

class SMART_Wire
{
  public:
    SMART_Wire(float wireResistance = 0, float recommendedCurrent = 0, float resistanceDropThreshold = 0, float X = 0, float Y = 0);
    int train(DPM8600 &converter);
    int apply(float c, float t);
    int activate(float t);
    float currentFor(float t);
    float timeFor(float c);


    // Future functions:
    // activateAndHold
    // ADD options for training with init = measured or first measured.

    float R;
    float Rth;
    float coeff[2];
    float cMin;
    float cMax;
    float tMin;
    float tMax;

  private:
    DPM8600 *_converter;
    float _errorNum;
    float _rC;
    static const float _rMin;
    static const float _rMax;
    void calculateBoundaries();
    float measureResistance();
    float measureResistanceQuick();
    float measureResistanceDrop();
    void measureCoefficients(float &x, float &y);
    bool activateWith(float c, float &t);
};


#endif
