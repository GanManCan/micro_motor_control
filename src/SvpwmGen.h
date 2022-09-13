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
* The time class represents a moment of time.
*/

#ifndef SVPWMGEN_H
#define SVPWMGEN_H

class svpwmGen
{
public:
  
  svpwmGen(float pwmFreq, float vdc); 
  float calculateSVPWM(float vAlpha, float vBeta); 


private: 
  float _pwmFreq; 
  float _vdc; 
};

#endif //SVPWMGEN_H