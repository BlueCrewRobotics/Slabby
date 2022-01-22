/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set the default command for the Drive Train
  m_subDriveTrain.SetDefaultCommand(CmdDriveTrain(&m_subDriveTrain, driverController));
  

}

void RobotContainer::ConfigureButtonBindings() {
  
  // Configure your button bindings here
  driverController_button_rbump->WhenPressed(new CmdShiftGear(&m_subPneumatics));
    
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

/*
  This function will be run in RobotInit() to intialize the 
  talons and victors for the drive train
*/
void RobotContainer::ConfigureDrive() {
  m_subDriveTrain.Configure();
  m_subDriveTrain.ConfigurePID();
}

void RobotContainer::ConfigureCompressor() {
  m_subPneumatics.ConfigureCompressor();
}

// Gets the speed to pass into the default command for the drive train
double RobotContainer::GetSpeed() {
  double speed;
  if(driverController->GetRawAxis(AXIS_L_TRIG) > 0)
  {
    speed = driverController->GetRawAxis(AXIS_L_TRIG);
  }
  else
  {
    speed = driverController->GetRawAxis(AXIS_R_TRIG);
  }
  //wpi::outs() << "Testing!\n";
  //wpi::outs() << "Testing again!\n";
  //wpi::outs() << m_speed << " \n";
  return speed;
}

// Gets the rotation to pass into the default command for the drive train
double RobotContainer::GetRotation() {
  double rotation;
  rotation = driverController->GetRawAxis(AXIS_LX);
  return rotation;
}

void RobotContainer::ConfigureShooter() {
  m_subShooter.Configure();
}