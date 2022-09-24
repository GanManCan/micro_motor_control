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
  uint32_t tempTest = svpwmBaseTestUint32.calculateAngle((uint32_t)1, (uint32_t)1); 
  double tempFloat = svpwmBaseTestFloat.calculateAngle(1.0, 1.0);

  std::cout << "Angle (uint32_t): " << tempTest <<"\n";
  std::cout << "Angle (float): " << tempFloat <<"\n";

  
  LONGS_EQUAL(tempTest,1);
}


