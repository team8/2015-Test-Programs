#include "Robot.h"

Robot::Robot():
	arm()
{

}

void Robot::init()
{
	arm.init();
}

void Robot::update()
{
	arm.update();
}

void Robot::disable()
{
	arm.disable();
}
