/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_TalonSRX.h"
#include "BC_VictorSPX.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  //void InitDefaultCommand() override;
  void Configure();
  void ConfigurePID();
  void Drive(double speed, double rotation);
  void DriveVelocityControl(double speed, double rotation);
  void SetRamp(double ramp);
  void ResetEncoders();
  void ConfigureAuto();
  void AutoDrive(double leftrotations, double rightrotations);
  void ConfigMotionMagicCurve(int strength);
  void AutoRotate(double degrees);
  int GetLeftMotorPosition();
  int GetRightMotorPosition();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.


  BC_TalonSRX *leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
  BC_TalonSRX *rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);

  BC_VictorSPX* leftFollowMotor = new BC_VictorSPX(MOTOR_LEFT_FOLLOWER); 		
  BC_VictorSPX* rightFollowMotor = new BC_VictorSPX(MOTOR_RIGHT_FOLLOWER);


  frc::DifferentialDrive *driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);
};
