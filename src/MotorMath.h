/**
* @file
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

#ifndef MOTORMATH_H
#define MOTORMATH_H

class motorMath
{
public:
  
  /**
   * Calcualte the dq transofrm D Phase
   * @param phaseAlpha,phaseBeta Input values.  
  */
  float dqTransformPhaseD(float phaseAlpha,float phaseBeta,float thetaRadians);

  /**
   * Calculate the the dq transform Q Phase 
   * @param phaseAlpha, phaseBeta, thetaRadians
  */ 
  float dqTransformPhaseQ(float phaseAlpha,float phaseBeta,float thetaRadians);   
  float clarkeTransformAlpha(float phaseA,float phaseB,float phaseC); 
  float clarkeTransformBeta(float phaseA,float phaseB,float phaseC); 

  //float calculate

private:

};

#endif