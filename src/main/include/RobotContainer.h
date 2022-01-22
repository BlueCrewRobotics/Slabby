/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"
#include "commands/ExampleCommand.h"
#include "commands/CmdDriveTrain.h"
#include "commands/CmdShiftGear.h"


#include "subsystems/ExampleSubsystem.h"

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPneumatics.h"
#include "subsystems/SubShooter.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  void ConfigureDrive();
  void ConfigureCompressor();
  void ConfigureShooter();
  double GetSpeed();
  double GetRotation();

 private:
  
  // The robot's subsystems
  SubDriveTrain m_subDriveTrain;
  SubPneumatics m_subPneumatics;
  SubShooter m_subShooter;
  
  
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;


  // Setup driver controller
  frc::Joystick *driverController = new frc::Joystick(DRIVER_CONTROLLER);

  // LEFT TRIGGER // Drive Backwards use driverController->GetRawAxis(AXIS_L_TRIG)
  // RIGHT TRIGGER // Drive Forwards use driverController->GetRawAxis(AXIS_R_TRIG)
  // LEFT STICK LEFT // Turn Left driverController->GetRawAxis(AXIS_LX)
  // LEFT STICK RIGHT // Turn Right driverController->GetRawAxis(AXIS_LX)
  
  frc2::JoystickButton *driverController_button_a = new frc2::JoystickButton(driverController, BUTTON_A); // Not Used
  frc2::JoystickButton *driverController_button_b = new frc2::JoystickButton(driverController, BUTTON_B); // Low gear mode
  frc2::JoystickButton *driverController_button_x = new frc2::JoystickButton(driverController, BUTTON_X); // Not Used
  frc2::JoystickButton *driverController_button_y = new frc2::JoystickButton(driverController, BUTTON_Y); // Intake ball
  frc2::JoystickButton *driverController_button_lbump = new frc2::JoystickButton(driverController, BUTTON_L_BUMP); // Not Used
  frc2::JoystickButton *driverController_button_rbump = new frc2::JoystickButton(driverController, BUTTON_R_BUMP); // Used in gear shifting
  frc2::JoystickButton *driverController_button_select = new frc2::JoystickButton(driverController, BUTTON_SELECT); // Not Used 
  frc2::JoystickButton *driverController_button_start = new frc2::JoystickButton(driverController, BUTTON_START); // Not Used
  frc2::JoystickButton *driverController_button_l3 = new frc2::JoystickButton(driverController, BUTTON_L3); // Not Used
  frc2::JoystickButton *driverController_button_r3 = new frc2::JoystickButton(driverController, BUTTON_R3); // Not Used

  // Setup auxilary controller   
/*  frc::Joystick *auxController = new frc::Joystick(AUX_CONTROLLER);

  frc2::JoystickButton *auxController_button_a = new frc2::JoystickButton(auxController, BUTTON_A);  
  frc2::JoystickButton *auxController_button_b = new frc2::JoystickButton(auxController, BUTTON_B); 
  frc2::JoystickButton *auxController_button_x = new frc2::JoystickButton(auxController, BUTTON_X); 
  frc2::JoystickButton *auxController_button_y = new frc2::JoystickButton(auxController, BUTTON_Y); 
  frc2::JoystickButton *auxController_button_lbump = new frc2::JoystickButton(auxController, BUTTON_L_BUMP); 
  frc2::JoystickButton *auxController_button_rbump = new frc2::JoystickButton(auxController, BUTTON_R_BUMP); 
  frc2::JoystickButton *auxController_button_select = new frc2::JoystickButton(auxController, BUTTON_SELECT); 
  frc2::JoystickButton *auxController_button_start = new frc2::JoystickButton(auxController, BUTTON_START); 
  frc2::JoystickButton *auxController_button_l3 = new frc2::JoystickButton(auxController, BUTTON_L3); 
  frc2::JoystickButton *auxController_button_r3 = new frc2::JoystickButton(auxController, BUTTON_R3);   
*/
  

  void ConfigureButtonBindings();
};
