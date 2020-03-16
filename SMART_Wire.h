/*
  SMART_Wire.h - Library for controlling Shape Memory Alloy Wires using resistance tracking methods. 
  Created by Timothy Lobiak, March 10, 2020.
  Released into the public domain.
*/

#ifndef SMART_Wire_h

#define SMART_Wire_h
#include "Arduino.h"
#include "DPM_8600.h"

class SMART_Wire
{
  public:
    SMART_Wire(float wireResistance = 0, float recommendedCurrent = 0, float resistanceDropThreshold = 0, float X = 0, float Y = 0);
    int train(DPM_8600 &converter);
    int activate(float t);
    float currentFor(float t);
    float timeFor(float c);


    // Future functions:
    // activateAndHold

    float R;
    float Rth;
    float coeff[2];
    float cMin;
    float cMax;
    float tMin;
    float tMax;

  private:
    DPM_8600 *_converter;
    float _errorNum;
    float _rC;
    static const float _rMin;
    static const float _rMax;
    void calculateBoundaries();
    float measureResistance();
    float measureResistanceQuick();
    float measureResistanceDrop();
    bool measureCoefficients(float &x, float &y);
    bool activateWith(float c, float &t);
};


#endif
