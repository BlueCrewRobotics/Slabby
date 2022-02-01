// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"


SubShooter::SubShooter() = default;

// This method will be called once per scheduler run
void SubShooter::Periodic() {
    SpinUpWheels(frc::SmartDashboard::GetNumber("Shooter/topSpeed", 0),frc::SmartDashboard::GetNumber("Shooter/botSpeed", 0));
    SetShooterAngle(frc::SmartDashboard::GetNumber("Shooter/angle", 0));
}

void SubShooter::Configure() {
    frc::SmartDashboard::PutNumber("Shooter/topSpeed",0.0);
    frc::SmartDashboard::PutNumber("Shooter/botSpeed",0.0);
    frc::SmartDashboard::PutNumber("Shooter/angle",0.0);

    topShooterMotor->SetInverted(true);
//    topShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
//    topShooterMotor->SetSensorPhase(false);
//    topShooterMotor->ConfigClosedloopRamp(0.25, 0);


    bottomShooterMotor->SetInverted(true);
//    bottomShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
//    bottomShooterMotor->SetSensorPhase(false);
//    bottomShooterMotor->ConfigClosedloopRamp(0.25, 0);

    
/*    
    topShooterMotor->Config_kF(0,0.021, 0); //0.01704
    topShooterMotor->Config_kP(0,0.0225, 0); //0.023
    topShooterMotor->Config_kI(0,SHOOTER_TOP_KI_0, 0);
    topShooterMotor->Config_kD(0,SHOOTER_TOP_KD_0, 0); 

    bottomShooterMotor->Config_kF(0,0.02, 0);
    bottomShooterMotor->Config_kP(0,0.022, 0);
    bottomShooterMotor->Config_kI(0,SHOOTER_BTM_KI_0, 0);
    bottomShooterMotor->Config_kD(0,SHOOTER_BTM_KD_0, 0);

    topShooterMotor->SelectProfileSlot(0, 0);
    topShooterMotor->ConfigNominalOutputForward(0, 0);
    topShooterMotor->ConfigNominalOutputReverse(0, 0);
    topShooterMotor->ConfigPeakOutputForward(1, 0);
    topShooterMotor->ConfigPeakOutputReverse(-1, 0);
    
    bottomShooterMotor->SelectProfileSlot(0, 0);
    bottomShooterMotor->ConfigNominalOutputForward(0, 0);
    bottomShooterMotor->ConfigNominalOutputReverse(0, 0);
    bottomShooterMotor->ConfigPeakOutputForward(1, 0);
    bottomShooterMotor->ConfigPeakOutputReverse(-1, 0);
*/

    // Set current limit continuous, peak, and peak duration can only be set on
    // TalonSRX
    topShooterMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0);
    topShooterMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
    topShooterMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);

    bottomShooterMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0);
    bottomShooterMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
    bottomShooterMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);
}
void SubShooter::SpinUpWheels(double topSpeed, double bottomSpeed){

  topShooterMotor->Set(ControlMode::PercentOutput, topSpeed);
  bottomShooterMotor->Set(ControlMode::PercentOutput, bottomSpeed);

}

void SubShooter::SetShooterAngle(double angle) {
    angleServo->SetBounds(2.0,1.55,1.5,1.45,1.0);
    angleServo->SetPosition(angle);
}
