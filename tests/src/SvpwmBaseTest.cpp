/** Motor Math Tests **/

// To-do List
//  single input test
//  multiple input test
//  test min range limiting
//  test max range limit

#include "CppUTest/TestHarness.h"
#include <cmath>
#include "SvpwmBase.h"
#include <iostream>

TEST_GROUP(SvpwmBase)
{
  double compareThreshold = 1e-10;

  uint32_t pwmFreq = 10.0, vdc = 100.0;

  svpwmBase<uint32_t> svpwmBaseTest = svpwmBase(pwmFreq, vdc);
  
  void setup(){
    // Add setup code here   

  }

  void teardown(){
    // Add teardown code ehre
  }
};

TEST(SvpwmBase, TestFloatAngle)
{

  
  DOUBLES_EQUAL(0.0,1.0, compareThreshold);
}

