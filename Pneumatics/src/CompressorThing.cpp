#include <WPILib.h>

class CompressorThing : public IterativeRobot {

  public:

  private:
    Compressor compressor;
    Joystick stick;
    bool justPressed; 
    CompressorThing::CompressorThing();
};

CompressorThing::CompressorThing()
//I don't know the pressureSwitchChannel or the Pressure Switch Channel, so this instance of a compressor needs to be fixed.
	compressor((uint32_t)423, (uint32_t)432),
	stick((uint32_t)423)
	{

	}


void CompressorThing::TeleopPeriodic() {
	//When you press button four it changes if the compressor is started or not
	
	if(stick.GetRawButton((uint32_t)4) && !justPressed) {
		if(compressor.Enabled()) {
			compressor.Stop();
		}
		else if(!compressor.Enabled()) {
			compressor.Start(); 	
		}
	}
  
	justPressed = stick.GetRawButton((uint32_t)4);
}

}


