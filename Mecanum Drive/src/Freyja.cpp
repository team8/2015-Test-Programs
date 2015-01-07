class Freyja : public IterativeRobot {
public:
	Freyja();
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
	Robot robot;
	HumanController human;
};

Freyja::Freyja() :
robot(),
human()
{

}

void Freyja::RobotInit() {
	robot.init();
}

void Freyja::AutonomousInit(){

}

void Freyja::AutonomousPeriodic() {

}

void Freyja::AutonomousDisabled() {

}

void Freyja::DisabledInit() {

}

void Freyja::DisabledPeriodic() {

}

void Freyja::TeleopInit() {
	robot.init();
	robot.update();
}

void Freyja::TeleopPeriodic() {
	human.update(&robot);
	robot.update();
}

void Freyja::TeleopDisabled() {
	robot.disable();
	robot.update();
}

void Freyja::TestInit() {

}

void Freyja::TestPeriodic() {

}

START_ROBOT_CLASS(Freyja);
