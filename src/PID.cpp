#include "PID.h"
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  total_error += pow(cte, 2.0);
}

double PID::TotalError() {
  return total_error;
}

double PID::CalculateSteeringAngle(double cte) {
  UpdateError(cte);
  
  std::chrono::time_point<std::chrono::system_clock> current_timestamp;
  current_timestamp = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = current_timestamp - prev_timestamp;
  
  double diff_cte;

  if (has_prev_cte) {
    double dt = diff.count();
    cte_sum += cte * dt;
    diff_cte = (cte - prev_cte)/dt;
  }
  else {
    diff_cte = cte;
    has_prev_cte = true;
  }
  prev_timestamp = current_timestamp;
  prev_cte = cte;

  return - Kp * cte - Kd * diff_cte - Ki * cte_sum;
}
