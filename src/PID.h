#ifndef PID_H
#define PID_H
#include <chrono>


class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  double CalculateSteeringAngle(double cte);
private:
  bool has_prev_cte = false;
  double prev_cte = 0;
  double cte_sum = 0;
  std::chrono::time_point<std::chrono::system_clock> prev_timestamp;
  double total_error = 0;
};

#endif /* PID_H */
