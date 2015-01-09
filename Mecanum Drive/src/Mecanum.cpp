#include <WPILib.h>
#include "Mecanum.h"
#include "Constants.h"

//Initializes the joysticks and state
Mecanum::Mecanum() :
	driveStick(new Joystick((uint32_t) 4)),
	turnStick(new Joystick((uint32_t) 2)),
	state(AUTONOMOUS), xSpeed(0),
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
		robotDrive->
		MecanumDrive_Cartesian(xSpeed, ySpeed, rotation);
		break;
	case TELEOP:
		robotDrive->
		MecanumDrive_Cartesian(driveStick->GetX(),
			driveStick->GetY(),
			turnStick->GetX());
		break;
	}
}

void Mecanum::disable() {
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
