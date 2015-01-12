#include <WPILib.h>
#include "Robot.h"

class PneumaticsRobot : public IterativeRobot
{
	private:
		Robot robot;

	public:
		PIDRobot();
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
};

PneumaticsRobot::PneumaticsRobot():
	robot();
{

}

void PneumaticsRobot::RobotInit()
{
	robot.init();
}

void PneumaticsRobot::AutonomousInit()
{
	robot.init();
}

void PneumaticsRobot::AutonomousPeriodic()
{
	robot.update();
}

void PneumaticsRobot::AutonomousDisabled()
{

}

void PneumaticsRobot::DisabledInit()
{
	robot.disable();
}

void PneumaticsRobot::DisabledPeriodic()
{
	robot.disable();
	robot.update();
}

void PneumaticsRobot::TeleopInit()
{
	robot.init();
}

void PneumaticsRobot::TeleopPeriodic()
{
	robot.update();
}

void PneumaticsRobot::TeleopDisabled()
{
	robot.disable();
	robot.update();
}

void PneumaticsRobot::TestInit()
{

}
void PneumaticsRobot::TestPeriodic()
{

}
START_ROBOT_CLASS(PneumaticsRobot);




