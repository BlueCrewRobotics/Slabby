// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include "Constants.h"

class SubPneumatics : public frc2::SubsystemBase {
 public:
  SubPneumatics();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void ConfigureCompressor(); // Configures the Compressor to run in closed loop control
  void SwitchDriveTrainGear(); // Inverts the gear solenoid


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  //  Creates the compressor class on the heap
  frc::Compressor *m_compressor = new frc::Compressor(PCM_SHIFTER,frc::PneumaticsModuleType::CTREPCM);
  // Creates the gear shifting solenoid on the heap
  frc::Solenoid *m_gearSolenoid = new frc::Solenoid(PCM_SHIFTER,frc::PneumaticsModuleType::CTREPCM,PCM_GEARSHIFT);
  
};
