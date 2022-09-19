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


template <typename T>
class svpwmBase
{
public:

  svpwmBase();

  svpwmBase(const T& pwmFreq, const T& vdc)
  {
    _pwmFreq = pwmFreq;
    _vdc = vdc; 
    _angle = 0; 
    _sector = 0; 

    std::cout << std::fixed; 
    std::cout << "Pwm Freq: " << _pwmFreq << "\n";

  };

  T calculateAngle()
  {
    return 0; 
  };


private: 
  T _pwmFreq; 
  T _vdc;  
  T _sector; 
 
};

#endif //SVPWMGEN_H