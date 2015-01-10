#include <WPILib.h>

class Mecanum: public IterativeRobot {
private:
	RobotDrive *robotDrive;
	Joystick *driveStick;
	Joystick *turnStick;
public:
	Mecanum();
	void TeleopPeriodic();
};

Mecanum::Mecanum() :
		driveStick(new Joystick((uint32_t) 1)), turnStick(
				new Joystick((uint32_t) 2)) {
	driveStick->SetAxisChannel(Joystick::kTwistAxis, 3);
	robotDrive = new RobotDrive(10, 9, 1, 2);
}

void Mecanum::TeleopPeriodic(void) {
	std::printf("Updating");
	robotDrive -> MecanumDrive_Cartesian(driveStick->GetX(), driveStick->GetY(),
			turnStick->GetX());
}

START_ROBOT_CLASS(Mecanum);
