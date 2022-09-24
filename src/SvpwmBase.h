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


template <typename T>
class svpwmBase
{
public:

  svpwmBase();

  svpwmBase(const T& pwmFreq, const T& vdc)
  {
    _pwmFreq = pwmFreq;
    _vdc = vdc; 
    //_angle = 0; 
    _sector = 0; 

    std::cout << std::fixed; 
    std::cout << "Pwm Freq: " << _pwmFreq << "\n";

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

  // angle = arctan(Vq/Vd)

  T calculateAngle(const T& vDphase, const T& vQphase)
  {
    std::cout << "Invalid Input Type \n";
    return 1; 
  };

  template<> double calculateAngle(const double& vDphase, const double& vQphase)
  {
    return 0.0; 
  };


private: 
  T _pwmFreq; 
  T _vdc;  
  T _sector; 
 
};

#endif //SVPWMGEN_H