#include "Robot.h"

Robot::Robot() :
drivetrain()
{

}

void Robot::init() {
	drivetrain->init();
}

void Robot::disable() {
	drivetrain->disable();
}

void Robot::update() {
	drivetrain->update();
}

void Robot::move(double linear, double curvy) {
	drivetrain->meep(linear, curvy);
}
