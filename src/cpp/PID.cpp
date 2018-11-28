//PID
#include <PID.h>



void PID::run_PID(bool b_test) { 
drive_talon_left_enc -> SetSensorPhase(false);
drive_talon_right_enc -> SetSensorPhase(false);
flipper_talon_enc -> SetSensorPhase(false);
int drive_talon_left_enc_pos;
int drive_talon_right_enc_pos;
int flipper_talon_enc_pos;
double fP;
double fI;
double fD;
  if (b_test == 1) 
  {
    bool flipper_test = SmartDashboard::GetBoolean("DB/Button 1", false);
    bool run_motors = SmartDashboard::GetBoolean("DB/Button 2", false);
  
    drive_talon_left_enc -> Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 0", "0.0").c_str()), 10);
    drive_talon_left_enc -> Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 1", "0.0").c_str()), 10);
    drive_talon_left_enc -> Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 2", "0.0").c_str()), 10);
    drive_talon_right_enc -> Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 5", "0.0").c_str()), 10);
    drive_talon_right_enc -> Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 6", "0.0").c_str()), 10);
    drive_talon_right_enc -> Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 7", "0.0").c_str()), 10);
    flipper_talon_enc -> Config_kP(0, fP = SmartDashboard::GetNumber("DB/Slider 1", 0.0),10);
    flipper_talon_enc -> Config_kI(0, fI = SmartDashboard::GetNumber("DB/Slider 2", 0.0),10);
    flipper_talon_enc -> Config_kD(0, fD = SmartDashboard::GetNumber("DB/Slider 3", 0.0),10); 
    
    if (flipper_test == 1) 
    {
      flipper_talon_enc -> Set(ControlMode::Position, 20000);                
      std::cout << "Flipper pos error " << (20000 - flipper_talon_enc_pos);
      std::cout << "    Flipper pos " << (flipper_talon_enc_pos = flipper_talon_enc -> GetSelectedSensorPosition(0));
    }

    if (run_motors == 0)
    {
      drive_talon_left_enc -> Set(ControlMode::PercentOutput, 0);
      drive_talon_right_enc -> Set(ControlMode::PercentOutput, 0);
      drive_talon_left_enc -> SetSelectedSensorPosition(0, 0, 10);
      drive_talon_right_enc -> SetSelectedSensorPosition(0, 0, 10);
      

    }
    if (flipper_test == 0)
    {
      flipper_talon_enc -> Set(ControlMode::PercentOutput, 0);
      flipper_talon_enc -> SetSelectedSensorPosition(0, 0, 10);
    }


    if (run_motors == 1)
    { 
      drive_talon_left_enc -> Set(ControlMode::Position, 20000);
      drive_talon_right_enc -> Set(ControlMode::Position, 20000);
    }
  std::cout << "Left pos " << (drive_talon_left_enc_pos = drive_talon_left_enc -> GetSelectedSensorPosition(0)) << std::endl;
  std::cout << "Right pos " << (drive_talon_right_enc_pos = drive_talon_right_enc -> GetSelectedSensorPosition(0)) << std::endl;
 
  std::cout << "        Left minus Right difference is " << (drive_talon_left_enc_pos - drive_talon_right_enc_pos) << std::endl;
  std::cout << "Left pos error " << (20000 - drive_talon_left_enc_pos) << std::endl;
  std::cout << "Right pos error " << (20000 - drive_talon_right_enc_pos) << std::endl;
  
  }

}