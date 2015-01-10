#include <WPILib.h>
#include "Mecanum.h"
#include "Constants.h"

//Initializes the joysticks and state
Mecanum::Mecanum() :
	driveStick(new Joystick((uint32_t) DRIVE_STICK)),
	turnStick(new Joystick((uint32_t) TURN_STICK)),
	state(TELEOP), xSpeed(0),
	ySpeed(0), rotation(0)
{
	robotDrive = new RobotDrive(TALON_LEFT_FRONT,
			TALON_LEFT_BACK,
			TALON_RIGHT_FRONT,
			TALON_RIGHT_BACK);
}

/*
 * If in teleop, just uses the joysticks to feed into the robotDrive
 * If in autonomous, can change the inputs based on autonomous controller
 */
void Mecanum::update() {
	switch(state) {
	case AUTONOMOUS:
		std::cout << "Autonomous mode";
		robotDrive->
		MecanumDrive_Cartesian(xSpeed, ySpeed, rotation);
		break;
	case TELEOP:
		std::cout << "Teleop mode";
		robotDrive->
		MecanumDrive_Cartesian(driveStick->GetX(),
			driveStick->GetY(),
			turnStick->GetX());
		break;
	}
}

void Mecanum::disable() {
	std::cout << "Disabled";
	robotDrive->MecanumDrive_Cartesian(0, 0, 0);
}

void Mecanum::setX(float speed) {
	xSpeed = speed;
}

void Mecanum::setY(float speed) {
	ySpeed = speed;
}

void Mecanum::setRotation(float rotate) {
	rotation = rotate;
}

void Mecanum::setAuto(bool autonomous) {
	if(autonomous) {
		state = AUTONOMOUS;
	}
	else {
		state = TELEOP;
	}
}
