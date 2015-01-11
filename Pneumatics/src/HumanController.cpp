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

}



