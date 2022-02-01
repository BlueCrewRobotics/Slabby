/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once
#include <ctre/Phoenix.h>
#include "Constants.h"

class BC_FalconFX : public virtual frc::SpeedController {
 public:
  BC_FalconFX(int device);
  



  // Overrides for SpeedController class
  void Set(double speed);
  void Disable();
	void StopMotor();

 private:
  TalonFX* ptr_falconFX = nullptr;  

	double m_dSpeed = 0;
	bool m_bSelectedGear = 0;
	int m_iCount;
	double m_dMaxSpeed = VELOCITY_SP_MAX_LG;

};
