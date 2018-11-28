#include <PID.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>

using namespace frc;

    
class Robot: public IterativeRobot {

private:
    TalonSRX *drive_talon_left_enc, *drive_talon_right_enc, *flipper_talon_enc;
    PID *pid;
    void RobotInit() {
        drive_talon_left_enc = new TalonSRX(2);
        drive_talon_right_enc = new TalonSRX(3);
        flipper_talon_enc = new TalonSRX(4);
        pid = new PID(drive_talon_right_enc, drive_talon_left_enc, flipper_talon_enc);
    std::cout << "Kevboi yeet lez go PID yees v.2";
                                      
    }

    void DisabledInit() { }
    void AutonomousInit() { }
    void TeleopInit() { 
     
    }
    void TestInit() { }

    void DisabledPeriodic() { }
    void AutonomousPeriodic() { }
    void TeleopPeriodic() { 
     pid -> run_PID(1);

   
   } 
    void TestPeriodic() { }
};

START_ROBOT_CLASS(Robot)