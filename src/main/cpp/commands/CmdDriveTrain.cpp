/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#include "commands/CmdDriveTrain.h"

CmdDriveTrain::CmdDriveTrain(SubDriveTrain* driveTrain, double speed, double rotation) : m_driveTrain{driveTrain}, m_speed{speed}, m_rotation{rotation} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
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
