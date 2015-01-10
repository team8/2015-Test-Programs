#include <WPILib.h>
#include <iostream>
class SolenoidRobot : public IterativeRobot {

  public:
    SolenoidRobot();
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
    Talon talon;

};

SolenoidRobot::SolenoidRobot():
	solenoid((uint32_t)0, (uint32_t)1),
	stick((uint32_t)0),
	talon((uint32_t)9)
	{
		justPressedFR = false;
		justPressedOF = false;
	}

void SolenoidRobot::RobotInit() {

}

void SolenoidRobot::AutonomousInit() {

}

void SolenoidRobot::AutonomousPeriodic() {

}

void SolenoidRobot::AutonomousDisabled() {
}

void SolenoidRobot::DisabledInit() {

}

void SolenoidRobot::DisabledPeriodic() {

}

void SolenoidRobot::TeleopInit() {

}

void SolenoidRobot::TeleopPeriodic() {
	//When you press button two it changes the solenoid value
	talon.Set(-1.0);
	
	if(stick.GetRawButton((uint32_t)2) && !justPressedFR) {
		std::cout << "raw button 2" << std::endl;
		if(solenoid.Get() == DoubleSolenoid::Value::kForward) {
			std::cout << "raw button 2 kforward" << std::endl;
			solenoid.Set(DoubleSolenoid::Value::kReverse); 	
		}
		else if(solenoid.Get() == DoubleSolenoid::Value::kReverse) {
			solenoid.Set(DoubleSolenoid::Value::kForward); 	
		}
	}
  if(stick.GetRawButton((uint32_t)3) && !justPressedOF) {
	  std::cout << "raw button 3" << std::endl;
		if(solenoid.Get() == DoubleSolenoid::Value::kForward) {
			solenoid.Set(DoubleSolenoid::Value::kOff); 	
		}
		else if(solenoid.Get() == DoubleSolenoid::Value::kOff) {
			solenoid.Set(DoubleSolenoid::Value::kForward);
		}
	}
	justPressedFR = stick.GetRawButton((uint32_t)2);
	justPressedOF = stick.GetRawButton((uint32_t)3);
}

void SolenoidRobot::TeleopDisabled() {

}

void SolenoidRobot::TestInit() {
}

void SolenoidRobot::TestPeriodic() {
	
}

START_ROBOT_CLASS(SolenoidRobot);
