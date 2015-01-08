#define <WPILib>

class Compressor : public IterativeRobot {

  public:
    Compressor();
    void RobotInit();
	  void AutonomousInit();
	  void AutonomousPeriodic();
	  void AutonomousDisabled();
	  void DisabledInit();
	  void DisabledPeriodic();
	  void TeleopInit();
	  void TeleopPeriodic();
	  void TeleopDisabled();
	  void TestInit();
	  void TestPeriodic();
  private:
    Compressor compressor;
    Joystick stick;
    bool justPressed; 

};

Compressor::Compressor():
//I don't know the pressureSwitchChannel or the Pressure Switch Channel, so this instance of a compressor needs to be fixed.
	compressor((uint32_t)423, (uint32_t)432),
	stick((uint32_t)423),
{
 justPressed = false;
}
void Compressor::RobotInit() {

}

void Compressor::AutonomousInit() {

}

void Compressor::AutonomousPeriodic() {

}

void Compressor::AutonomousDisabled() {
}

void Compressor::DisabledInit() {

}

void Compressor::DisabledPeriodic() {

}

void Compressor::TeleopInit() {

}

void Compressor::TeleopPeriodic() {
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

void Compressor::TeleopDisabled() {

}

void Compressor::TestInit() {
}

void Compressor::TestPeriodic() {
	
}

START_ROBOT_CLASS(Compressor);
