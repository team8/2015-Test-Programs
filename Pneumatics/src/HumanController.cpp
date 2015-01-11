#include <WPILib.h>
#include "HumanController.h"
#include "Constants.h"
#include "Arm.h"

HumanController::HumanController(Robot *robot):
	operatorController((uint32_t) PORT_OPERATOR_CONTROLLER)
{
	this->robot = robot;
}

void HumanController::update()
{
	if(operatorController.getRawButton((uint32_t) ARM_FORWARD_BUTTON))
	{
		this->robot.setArmState(EXTENDING);
	}
	
	if(operatorController.getRawButton((uint32_t) ARM_REVERSE_BUTTON))
	{
		this->robot.setArmState(RETRACTING);
	}
	else
	{
		this.robot.setArmState(IDLE);
	}
}



