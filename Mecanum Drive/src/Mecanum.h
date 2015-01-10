#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <WPILib.h>

class Mecanum {
private:
	//Swapping control from teleop and autonomous
	typedef enum DriveState {
		AUTONOMOUS, TELEOP
	} DriveState;
	DriveState state;

	//The pointers for the WPI controls to work
	RobotDrive *robotDrive;
	Joystick *driveStick;
	Joystick *turnStick;

	//Variables for autonomous driving
	float xSpeed;
	float ySpeed;
	float rotation;
public:
	Mecanum();
	void update();
	void disable();
	void setX(float speed);
	void setY(float speed);
	void setRotation(float rotate);
	void setAuto(bool autonomous);
};

#endif
