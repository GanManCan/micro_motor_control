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
  pidControl(float dt, float max, float min, float kp, float kd, float ki);


  float calculate(float setpoint, float system_feedback); 

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