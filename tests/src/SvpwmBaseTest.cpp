/** Motor Math Tests **/

// To-do List
//  single input test
//  multiple input test
//  test min range limiting
//  test max range limit
//  Check that the types are limited to certain types


#include "CppUTest/TestHarness.h"
#include <cmath>
#include "SvpwmBase.h"
#include <iostream>
#include <random>

TEST_GROUP(SvpwmBase)
{
  float compareThreshold = 1e-10;

  float pwmFreq = 10.0, vdc = 100.0;

  svpwmBase<float> svpwmBaseTestFloat = svpwmBase(pwmFreq, vdc);
  svpwmBase<uint32_t> svpwmBaseTestUint32 = svpwmBase((uint32_t)pwmFreq, (uint32_t)vdc);
  svpwmBase<int> svpwmBaseTestInt = svpwmBase(10, 100);
  
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
    float angleCalc = svpwmBaseTestFloat.calculateAngle(randomD, randomQ);
    DOUBLES_EQUAL(angleHardCode, angleCalc, compareThreshold);

    //std::cout << "RandomD, RandomQ: " << randomD << ", "<< randomQ <<"\n";
  } //for (int )
  
};

//TEST(SvpwmBase, CompareFloatAndFixedAngle)

