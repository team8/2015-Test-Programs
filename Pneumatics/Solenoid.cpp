#define <WPILib>

class Solenoid : public IterativeRobot {

  public:
    Solenoid();
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
    DoubleSolenoid solenoid;
    Joystick stick;
    bool justPressedFR;	//forward/reverse
    bool justPressedOF; //on/off

};

Solenoid::Solenoid():
	solenoid((uint32_t)423, (uint32_t)432),
	stick((uint32_t)423) 
	{
		justPressedFR = false;
		justPressedOF = false;
	}

void Solenoid::RobotInit() {

}

void Solenoid::AutonomousInit() {

}

void Solenoid::AutonomousPeriodic() {

}

void Solenoid::AutonomousDisabled() {
}

void Solenoid::DisabledInit() {

}

void Solenoid::DisabledPeriodic() {

}

void Solenoid::TeleopInit() {

}

void Solenoid::TeleopPeriodic() {
	//When you press button two it changes the solenoid value
	
	if(stick.GetRawButton((uint32_t)2) && !justPressedFR) {
		if(solenoid.Get() == DoubleSolenoid::Value::kForward) {
			solenoid.Set(DoubleSolenoid::Value::kReverse); 	
		}
		else if(solenoid.Get() == DoubleSolenoid::Value::kReverse) {
			solenoid.Set(DoubleSolenoid::Value::kForward); 	
		}
	}
  if(stick.GetRawButton((uint32_t)3) && !justPressedOF) {
		if(solenoid.Get() == DoubleSolenoid::Value::kOn) {
			solenoid.Set(DoubleSolenoid::Value::kOff); 	
		}
		else if(solenoid.Get() == DoubleSolenoid::Value::kOff) {
			solenoid.Set(DoubleSolenoid::Value::kOn); 	
		}
	}
	justPressedFR = stick.GetRawButton((uint32_t)2);
	justPressedOF = stick.GetRawButton((uint32_t)3);
}

void Solenoid::TeleopDisabled() {

}

void Solenoid::TestInit() {
}

void Solenoid::TestPeriodic() {
	
}

START_ROBOT_CLASS(Solenoid);
