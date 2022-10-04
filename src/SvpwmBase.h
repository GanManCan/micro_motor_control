/**
* @file
* @author Jan Doe <jandoe@example.com>
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* 
*/


#ifndef SVPWMBASE_H
#define SVPWMBASE_H

#include <iostream>
#include <cmath>


template <class T> class svpwmBase
{
public:

  svpwmBase();

  svpwmBase(const T& pwmFreq, const T& vdc, const T& svpwmPeriod)
  {
    _pwmFreq = pwmFreq;
    _vdc = vdc; 
    //_angle = 0; 
    _sector = 0; 
    _svpwmPeriod = svpwmPeriod;

  };

  /* Calculate Sector 
  *   vref1 = Uq
  *   vref2 = sin(60)Ud - sin(30)Uq
  *   vref3 = -sin(60)Ud - sin(30)Uq
  *  
  *   N = sign(vref1)+ 2*sign(vref2) + 4*sign(vref4)
  * 
  *     N    | 1 | 2 | 3 | 4 | 5 | 6 |  
  *   Sector | 1 | 5 | 0 | 2 | 3 | 4 |  
  */
  T calculateSector(const T& vDphase, const T& vQphase)
  {
    return 0; 
  };

 

  T calculateAngleFull(const T& vDphase, const T& vQphase)
  {
    std::cout << "Run UndefinedType \n";
    return 1; 
  };

  T calculateTa(const float& alpha)
  {

  };




private: 
  T _pwmFreq; 
  T _vdc;  
  T _sector; 
  T _svpwmPeriod;
 
}; // template Class T


/******* Template Methods Overrides *****************/


// angle of point (vd,vq)
template <>
class svpwmBase<float>
{
public:
  svpwmBase();

  svpwmBase(const float& pwmFreq, const float& vdc, const float& svpwmPeriod)
  {
    _pwmFreq = pwmFreq;
    _pwmPeriod = 1/pwmFreq;
  };

  float calculateAngleFull(const float& vDphase, const float& vQphase)
  {
    // Q phase is the Y axis
    float tempAngle = atan2f(vQphase, vDphase);
    return tempAngle;
  };

  float calculateAngleBound(const float& angle)
  {
    
    float returnAngle = 0;

    // Use if else vice fmod for speed
    if(angle < 0.0f) returnAngle = 0.0f; 
    else if(angle <= 60.0f) returnAngle = angle;
    else if(angle <= 120.0f) returnAngle = angle-60.0f;
    else if(angle <= 180.0f) returnAngle = angle-120.0f;
    else if(angle <= 240.0f) returnAngle = angle-180.0f;
    else if(angle <= 300.0f) returnAngle = angle-240.0f;
    else if(angle <= 360.0f) returnAngle = angle-300.0f;
    else if(angle >= 360.0f) returnAngle = 0.0f; 

    return returnAngle;
  };

  float calculateSector(const float& angle)
  {
    return 0.0;
  };

  float calculateTa(const float& alpha, const float& modIndex)
  {
    float taCalc = modIndex*(cos(alpha)-sin(alpha)/sqrt(3));
    return taCalc; 
  };



private: 
  float _pwmFreq; 
  float _pwmPeriod; 
  float _vdc;  
  float _sector; 
  float _svpwmPeriod;


}; // class svpwmBase<float>


#endif //SVPWMGEN_H