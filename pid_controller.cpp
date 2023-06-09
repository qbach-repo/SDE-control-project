/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   _pError = 0.0;
   _iError = 0.0;
   _dError = 0.0;
   
   _Kp = Kpi;
   _Ki = Kii;
   _Kd = Kdi;
   
   _output_lim_max = output_lim_maxi;
   _output_lim_min = output_lim_mini;
   
   dT = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   _dError = cte - _pError;
   _pError = cte;
   _iError += cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
   double control;
   
   control = - _Kp * _pError - _Kd * _dError - _Ki * _iError;
   
   if (control <= _output_lim_min)
   {
      return _output_lim_min;
   }
   else if (control >= _output_lim_max)
   {
      return _output_lim_max;
   }
   
   return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   dT = new_delta_time;
}
