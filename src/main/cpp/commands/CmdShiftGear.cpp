// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdShiftGear.h"

CmdShiftGear::CmdShiftGear(SubPneumatics* subsystem)  : m_subPneumatics(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void CmdShiftGear::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdShiftGear::Execute() {
  m_subPneumatics->SwitchDriveTrainGear();
}

// Called once the command ends or is interrupted.
void CmdShiftGear::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdShiftGear::IsFinished() {
  return true;
}
