
#include <WPILib.h>
#include "HumanController.h"
#include "Constants.h"
#include "Arm.h"

HumanController::HumanController(Robot *robot) :
		operatorController((uint32_t) PORT_OPERATOR_CONTROLLER)
{
	this->robot = robot;
}

void HumanController::update()
{
	if(operatorController.GetRawButton((uint32_t) ARM_FORWARD_BUTTON))
	{
		robot -> setArmState(Arm::EXTENDING);
	}
	if(operatorController.GetRawButton((uint32_t) ARM_REVERSE_BUTTON))
	{
		robot -> setArmState(Arm::RETRACTING);
	}
	if(!operatorController.GetRawButton((uint32_t) ARM_FORWARD_BUTTON) && !operatorController.GetRawButton((uint32_t) ARM_REVERSE_BUTTON))
	{
		robot -> setArmState(Arm::IDLE);
	}
}

