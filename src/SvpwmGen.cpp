#include "SvpwmGen.h"

svpwmGen::svpwmGen(float pwmFreq, float vdc)
{
  _pwmFreq = pwmFreq;
  _vdc = vdc; 
  _alpha = 0; 

}

svpwmGen::calculateSVPWM(float vAlpha, float vBeta)
{
  _alpha
}