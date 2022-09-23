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

  double pwmFreq = 10.0, vdc = 100.0;

  svpwmBase<double> svpwmBaseTestFloat = svpwmBase(pwmFreq, vdc);
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
  //float vQ = 1.0, vD = 1.0; 
  int tempTest = svpwmBaseTestInt.calculateAngle(1, 1); 

  std::cout << "Angle (Float): " << tempTest <<"\n";
  
  LONGS_EQUAL(tempTest,1);
}

