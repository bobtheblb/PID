#ifndef PID_H

#define PID_H


#include <iostream>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace frc;

    
class PID {

    public:
        PID(   
    TalonSRX *drive_talon_right_enc,
    TalonSRX *drive_talon_left_enc,
    TalonSRX *flipper_talon_enc)    
    
    : drive_talon_left_enc(drive_talon_right_enc), 
      drive_talon_right_enc(drive_talon_left_enc),  
      flipper_talon_enc(flipper_talon_enc) {}; 

    void run_PID(bool b_test); 
  
private:

        

        TalonSRX* drive_talon_right_enc;
        TalonSRX* drive_talon_left_enc;
        TalonSRX* flipper_talon_enc;
    

};

#endif