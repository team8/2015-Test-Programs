#include "DriveTrain.h"
#include "Constants.h"
#include <WPILib.h>
using namespace std;

DriveTrain::DriveTrain():
	leftFrontVic((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
	leftBackVic((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
	rightBackVic((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),
	rightFrontVic((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
	
	leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
	rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),
	
	leftFrontController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftFrontVic),
	leftBackController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftBackVic),
	rightFrontController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &rightEncoder, &rightFrontVic),
	rightBackController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &rightEncoder, &rightBackVic)
	{
		setAllVics(0.0);

		leftEncoder.SetDistancePerPulse(LEFT_DPP);
		rightEncoder.SetDistancePerPulse(RIGHT_DPP);

		leftEncoder.Start();
		rightEncoder.Start();
	}



double DriveTrain::getMoveSpeed()
{
	return moveSpeed;
}

double DriveTrain::getRotateSpeed()
{
	return rotateSpeed;
}

void DriveTrain::setMoveSpeed(double moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void DriveTrain::setRotateSpeed(double rotateSpeed)
{
	this->rotateSpeed = rotateSpeed;
}

void DriveTrain::setAllVics(double speed)
{
	leftBackVic.Set(-speed);
	leftFrontVic.Set(-speed);
	rightBackVic.Set(speed);
	rightFrontVic.Set(speed);
}

void DriveTrain::init()
{
	leftEncoder.Reset();
	rightEncoder.Reset();
	
	leftEncoder.Start();
	rightEncoder.Start();
	
	setAllVics(0);

	leftFrontController.Enable();
	rightFrontController.Enable();
	leftBackController.Enable();
	rightBackController.Enable();

	leftFrontController.SetInputRange(-1, 1);
	rightFrontController.SetInputRange(-1,1);
	leftBackController.SetInputRange(-1,1);
	rightBackController.SetInputRange(-1,1);
}

void DriveTrain::update()
{
	double leftSpeed = min(max(moveSpeed - rotateSpeed, -1.0), 1.0);
	double rightSpeed = min(max(moveSpeed + rotateSpeed, -1.0), 1.0);
	
	leftBackVic.Set(-leftSpeed);
	leftFrontVic.Set(-leftSpeed);
	rightBackVic.Set(rightSpeed);
	rightFrontVic.Set(rightSpeed);

	leftFrontController.SetSetpoint(leftEncoder.GetDistance() + leftSpeed);
	leftBackController.SetSetpoint(leftEncoder.GetDistance() + leftSpeed);
	rightFrontController.SetSetpoint(rightEncoder.GetDistance() + rightSpeed);
	rightBackController.SetSetpoint(rightEncoder.GetDistance() + rightSpeed);
	
	if(leftEncoder.Get() != 0)
	{
		cout << "Left Encoder Value: " << leftEncoder.GetDistance() << endl;
	}
	if(rightEncoder.Get() != 0)
	{
		cout << "Right Encoder Value: " << rightEncoder.GetDistance() << endl;
	}
}

void DriveTrain::disable()
{
	setAllVics(0);
	leftEncoder.Reset();
	rightEncoder.Reset();

	leftFrontController.Disable();
	rightFrontController.Disable();
	leftBackController.Disable();
	rightBackController.Disable();
}
