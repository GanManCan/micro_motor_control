/** Motor Math Tests **/

/** To-do List
* Test Fixed Point Angle Calculation (Single/Multiple)
* Test Fixed Point Angle Overload
* Check that the types are limited to certain types
*/

#include "CppUTest/TestHarness.h"
#include <cmath>
#include "SvpwmBase.h"
#include <iostream>
#include <random>

TEST_GROUP(SvpwmBase)
{
  float compareThreshold = 1e-10;

  float pwmFreq = 10'000.0, vdc = 100.0, svpwmPeriod = 2048.0;

  svpwmBase<float> svpwmBaseTestFloat = svpwmBase(pwmFreq, vdc, svpwmPeriod);
  svpwmBase<uint32_t> svpwmBaseTestUint32 = svpwmBase((uint32_t)pwmFreq, (uint32_t)vdc, (uint32_t)svpwmPeriod);
  
  void setup(){
    // Add setup code here   

  }

  void teardown(){
    // Add teardown code ehre
  }
};

TEST(SvpwmBase, TestFloatAngle)
{
  //float angleHardCode = 0.0, angleFunction = 0;
  float lowRandom = -1000;
  float highRandom = 1000; 

  // Loop through random angle calculation tests
  for(int i = 0; i<1000; i++){

    float randomD = lowRandom+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(highRandom-lowRandom)));
    float randomQ = lowRandom+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(highRandom-lowRandom)));

    float angleHardCode = atan2f(randomQ, randomD);
    float angleCalc = svpwmBaseTestFloat.calculateAngleFull(randomD, randomQ);
    DOUBLES_EQUAL(angleHardCode, angleCalc, compareThreshold);

  } //for (int )
  
};

TEST(SvpwmBase, TestFloatTimerSetpoints)
{

  //float taHardcode = sin(M_PI)


}

TEST(SvpwmBase,TestFloatAngleBound){

  //float angleHardCode = 0.0, angleFunction = 0;
  float lowRandom = 0.0;
  float highRandom = 360.0; 

  // Loop through random angle calculation tests
  for(int i = 0; i<1000; i++){

    float randomAngle = lowRandom+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(highRandom-lowRandom)));
    float testValue = svpwmBaseTestFloat.calculateAngleBound(randomAngle);
    float hardValue = fmod(randomAngle,60.0);
    DOUBLES_EQUAL(testValue, hardValue, compareThreshold);
  } //for (int )

  
}

TEST(SvpwmBase, TestFloatAngleOutOfBounds)
{
  // check if negative or greater than 360 returns "0.0"
  float testValue = svpwmBaseTestFloat.calculateAngleBound(-0.9f);
  DOUBLES_EQUAL(testValue, 0.0, compareThreshold);

  testValue = svpwmBaseTestFloat.calculateAngleBound(-10.5f);
  DOUBLES_EQUAL(testValue, 0.0, compareThreshold);

  testValue = svpwmBaseTestFloat.calculateAngleBound(360.9f);
  DOUBLES_EQUAL(testValue, 0.0, compareThreshold);
}

TEST(SvpwmBase, TestFixedPointSingleAngle)
{

};
//TEST(SvpwmBase, CompareFloatAndFixedAngle)

