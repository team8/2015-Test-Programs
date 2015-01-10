#include <WPILib.h>
#include "Mecanum.h"
#include "Constants.h"

//Initializes the joysticks and state
Mecanum::Mecanum() :
	driveStick(new Joystick((uint32_t) DRIVE_STICK)),
	turnStick(new Joystick((uint32_t) TURN_STICK)),
	state(TELEOP), xSpeed(0),
	ySpeed(0), rotation(0),
	frontLeftV((uint32_t) TALON_LEFT_FRONT),
	frontRightV((uint32_t) TALON_RIGHT_FRONT),
	backLeftV((uint32_t) TALON_LEFT_BACK),
	backRightV((uint32_t) TALON_RIGHT_BACK)
{
	robotDrive = new RobotDrive((uint32_t) TALON_LEFT_FRONT,
			(uint32_t)TALON_LEFT_BACK,
			(uint32_t)TALON_RIGHT_FRONT,
			(uint32_t) TALON_RIGHT_BACK);
}

/*
 * If in teleop, just uses the joysticks to feed into the robotDrive
 * If in autonomous, can change the inputs based on autonomous controller
 */
void Mecanum::update() {
	switch(state) {
	case AUTONOMOUS:
		std::cout << "Autonomous mode";
		//robotDrive->MecanumDrive_Cartesian(xSpeed, ySpeed, rotation);
		break;
	case TELEOP:
		std::cout << "Teleop mode";
//		setVic(0, -1);
//		setVic(1, -1);
//		setVic(2, -1);
//		setVic(3, -1);
		robotDrive->MecanumDrive_Cartesian(driveStick->GetX(), driveStick->GetY(), turnStick->GetX());
		std::cout << "Mecanum drive called in TELEOP";
		break;
	}
}

void Mecanum::disable() {
	std::cout << "Disabled";
	//robotDrive->MecanumDrive_Cartesian(0, 0, 0);
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

void Mecanum::setVic(int vicNum, double val) {
	switch(vicNum) {
	case 0:
		std::cout << "Front right";
		frontRightV.Set(val);
		break;
	case 1:
		std::cout << "Front left";
		frontLeftV.Set(val);
		break;
	case 2:
		std::cout <<"Back left";
		backLeftV.Set(val);
		break;
	case 3:
		std::cout << "Back right";
		backRightV.Set(val);
		break;
	}
}
