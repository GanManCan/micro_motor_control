// Motor Math Class

#include "MotorMath.h"
#include <cmath>


float motorMath::dqTransformPhaseD(float phaseAlpha, float phaseBeta, float thetaRadians)
{
 float phaseD = cos(thetaRadians)*phaseAlpha + sin(thetaRadians)*phaseBeta; 
 return phaseD;  
}

float motorMath::dqTransformPhaseQ(float phaseAlpha, float phaseBeta, float thetaRadians)
{
  float phaseQ = -sin(thetaRadians)*phaseAlpha + cos(thetaRadians)*phaseBeta;
  return phaseQ; 
}

float motorMath::clarkeTransformAlpha(float phaseA,float phaseB, float phaseC)
{
  float phaseAlpha =  2.0/3.0*(phaseA-phaseB/2.0-phaseC/2.0);
  return phaseAlpha; 

}

float motorMath::clarkeTransformBeta(float phaseA,float phaseB, float phaseC)
{
  float phaseBeta = 2.0*sqrt(3.0)/3.0*(phaseB/2.0-phaseC/2.0);
  return phaseBeta;
}
