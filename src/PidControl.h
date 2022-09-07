//Development based on bradley219 PID C++ implementation


#ifndef PIDCONTROL_H
#define PIDCONTROL_H

class pidControl
{
public:

  /**
   * pidControl Class Constructor
   * @param dt 
   * @param max
   * @param min
   * @param kp
   * @param kd
   * @param ki 
   */
  pidControl(float dt, float max, float min, float kp, float ki, float kd);
  /** 
   * Clear internal integral and derivative stored errors
   * @param setpoint : PID Controller setpoint (reference value)
   * @param system_feedback : PID Controller current system value
   */
  float calculate(float setpoint, float system_feedback); 
  void  clearStoredErrors(); 

  // Deconstructor 
  //~pidControl(); 

private:
  float _dt;
  float _max;
  float _min;
  float _kp;
  float _kd;
  float _ki; 
  float _integralSum;
  float _previousError; 

};
#endif