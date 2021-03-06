/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/


#include "subsystems/BC_TalonSRX.h"
#include "Constants.h"
#include <ctre/Phoenix.h>
#include <iostream>

BC_TalonSRX::BC_TalonSRX(int device) {

  BC_TalonSRX::ptr_talonSRX = new TalonSRX(device);
}

void BC_TalonSRX::Set(double speed) {

	// Run in low gear
	if(m_bSelectedGear == false){  
		
		speed = speed*m_dMaxSpeed;
		ptr_talonSRX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_talonSRX->SelectProfileSlot(0,0);
	}
	// Run in high gear
	if(m_bSelectedGear == true){  
		speed = speed*VELOCITY_SP_MAX_HG;
		ptr_talonSRX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_talonSRX->SelectProfileSlot(1,0);
	}

}

void BC_TalonSRX::SetMotionMagic(double position){
	ptr_talonSRX->Set(ControlMode::MotionMagic, position);
}

void BC_TalonSRX::PIDWrite(double output) {}

double BC_TalonSRX::Get() const { return m_dSpeed; }

void BC_TalonSRX::SetInverted(bool isInverted) {

  ptr_talonSRX->SetInverted(isInverted);
}

bool BC_TalonSRX::GetInverted() const { return ptr_talonSRX->GetInverted(); }

void BC_TalonSRX::Disable() {
  ptr_talonSRX->SetNeutralMode(NeutralMode::Coast);
}

void BC_TalonSRX::StopMotor() {
  ptr_talonSRX->SetNeutralMode(NeutralMode::Brake);
}

int BC_TalonSRX::GetCtrlLoopError() {
  return ptr_talonSRX->GetClosedLoopError(0);
}

double BC_TalonSRX::GetCtrlLoopTarget() {
  return ptr_talonSRX->GetClosedLoopTarget(0);
}

void BC_TalonSRX::SetGear(bool gear) { m_bSelectedGear = gear; }

bool BC_TalonSRX::GetGear() const {
	return m_bSelectedGear;
}
void BC_TalonSRX::SetMaxSpeed(double maxSpeed) {
	m_dMaxSpeed = maxSpeed;
}
double BC_TalonSRX::GetMaxSpeed() {
	return m_dMaxSpeed;
}
void BC_TalonSRX::ResetSensorPosition() {
	ptr_talonSRX->SetSelectedSensorPosition(0, 0, 0);
}

void BC_TalonSRX::ConfigureMotionVelocity(int velocity, int timeout) {
	ptr_talonSRX->ConfigMotionCruiseVelocity(velocity, timeout);
}

void BC_TalonSRX::ConfigureMotionAcceleration(int acceleration, int timeout) {
	ptr_talonSRX->ConfigMotionAcceleration(acceleration, timeout);
}
void BC_TalonSRX::ConfigureMotionCurveStrength(int curveStrength, int timeout) {
	ptr_talonSRX->ConfigMotionSCurveStrength(curveStrength, timeout);
}

int BC_TalonSRX::GetMotorPosition() {
	return ptr_talonSRX->GetSelectedSensorPosition();
}