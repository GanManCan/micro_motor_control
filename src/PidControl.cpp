#include "PidControl.h"

pidControl::pidControl(float dt, float max, float min, float kp, float ki, float kd)
{
  _dt = dt;
  _max = max;
  _min = min;
  _kp = kp;
  _kd = kd;
  _ki = ki;
  _integralSum = 0.0; 
  _previousError = 0.0; 

}

float pidControl::calculate(float setpoint, float system_feedback)
{
  // Calculate error
  float error = setpoint - system_feedback; 

  // Calculate proportional control

  float pControl = _kp * error*_dt; 

  // Calculate integral control 
  _integralSum = _integralSum + error*_dt;
  float iControl = _ki*_integralSum;


  // Calculate derivative control
  float derivativeError = (error - _previousError)/_dt; 
  float dControl = _kd*derivativeError; 

  // Sum PID controls
  float pidOutput = pControl + iControl + dControl;

  if(pidOutput > _max)
    pidOutput = _max;
  else if(pidOutput < _min)
    pidOutput = _min; 

  // Save error to previous error
  _previousError = error; 

  // Return PID control output
  return pidOutput;
}

void pidControl::clearStoredErrors()
{
  _integralSum = 0; 
  _previousError = 0; 
}
