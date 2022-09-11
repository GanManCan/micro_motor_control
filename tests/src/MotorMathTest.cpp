/** Motor Math Tests **/

// To-do List
//  dqTransformMultipleRandomInput

#include "CppUTest/TestHarness.h"
#include <cmath>
#include "MotorMath.h"

TEST_GROUP(MotorMath)
{
  motorMath mathTest;

  void setup(){
    // Add setup code here   
  }

  void teardown(){
    // Add teardown code ehre
  }
};

TEST(MotorMath, dqTransformCorrectSingle)
{
  float phaseAlpha = 1.0;
  float phaseBeta = 1.0;
  float thetaRadian = 0.1;
  float phaseD = mathTest.dqTransformPhaseD(phaseAlpha, phaseBeta, thetaRadian);
  float phaseQ = mathTest.dqTransformPhaseQ(phaseAlpha, phaseBeta, thetaRadian);

  float phaseDTest = phaseAlpha*cos(thetaRadian) + phaseBeta*sin(thetaRadian);
  float phaseQTest = -1.0*phaseAlpha*sin(thetaRadian) + phaseBeta*cos(thetaRadian);


  LONGS_EQUAL(phaseDTest, phaseD);
  LONGS_EQUAL(phaseQTest, phaseQ);
}

TEST(MotorMath, clarkeTransformSingle)
{  
  float phaseA = 10.0; 
  float phaseB = 250.0;
  float phaseC = 110.0;

  float phaseAlpha = mathTest.clarkeTransformAlpha(phaseA,phaseB,phaseC);
  float phaseBeta  = mathTest.clarkeTransformBeta(phaseA,phaseB,phaseC);

  float phaseAlphaTest = 2.0/3.0*(phaseA - 0.5*phaseB - 0.5*phaseC);
  float phaseBetaTest = 2.0/3.0*(sqrt(3)*phaseB/2.0 - sqrt(3)*phaseC/2.0);

  LONGS_EQUAL(phaseAlphaTest, phaseAlpha);
  LONGS_EQUAL(phaseBetaTest, phaseBeta); 
}