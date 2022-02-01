/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#include "subsystems/BC_FalconFX.h"

BC_FalconFX::BC_FalconFX(int device) {
    BC_FalconFX::ptr_falconFX = new TalonFX(device);
}

void BC_FalconFX::Set(double speed) {
  
  // Run in low gear
	if(m_bSelectedGear == false){  
		
		speed = speed*m_dMaxSpeed;
		ptr_falconFX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_falconFX->SelectProfileSlot(0,0);
	}
	// Run in high gear
	if(m_bSelectedGear == true){  
		speed = speed*VELOCITY_SP_MAX_HG;
		ptr_falconFX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_falconFX->SelectProfileSlot(1,0);
	}
}

void BC_FalconFX::Disable() {
  ptr_falconFX->SetNeutralMode(NeutralMode::Coast);
}

void BC_FalconFX::StopMotor() {
  ptr_falconFX->SetNeutralMode(NeutralMode::Brake);
}
