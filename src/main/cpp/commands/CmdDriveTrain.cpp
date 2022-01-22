// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTrain.h"

CmdDriveTrain::CmdDriveTrain(SubDriveTrain* driveTrain, frc::Joystick *driverController ) : m_driveTrain{driveTrain}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);

}

// Called when the command is initially scheduled.
void CmdDriveTrain::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveTrain::Execute() {

 double speed;
  if(m_driverController->GetRawAxis(AXIS_L_TRIG) > 0)
  {
    speed = -1*m_driverController->GetRawAxis(AXIS_L_TRIG);
  }
  else
  {
    speed = m_driverController->GetRawAxis(AXIS_R_TRIG);
  }

  double rotation;
  rotation = m_driverController->GetRawAxis(AXIS_LX);

  m_driveTrain->Drive(speed, rotation);

}

// Called once the command ends or is interrupted.
void CmdDriveTrain::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveTrain::IsFinished() {
  return false;
}
