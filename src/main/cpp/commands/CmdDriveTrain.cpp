// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTrain.h"

CmdDriveTrain::CmdDriveTrain(SubDriveTrain* driveTrain, double speed, double rotation) : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
  m_speed = speed;
  m_rotation = rotation;
}

// Called when the command is initially scheduled.
void CmdDriveTrain::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveTrain::Execute() {
  m_driveTrain->Drive(m_speed,m_rotation);
}

// Called once the command ends or is interrupted.
void CmdDriveTrain::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveTrain::IsFinished() {
  return false;
}
