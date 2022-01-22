// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_TalonSRX.h"
#include <frc/smartdashboard/SmartDashboard.h>

class SubShooter : public frc2::SubsystemBase {
 public:
  SubShooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Configure();
  void SpinUpWheels(double topSpeed, double bottomSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX *topShooterMotor = new TalonSRX(SHOOTER_TOP_ADDR);
  TalonSRX *bottomShooterMotor = new TalonSRX(SHOOTER_BTM_ADDR);

};
