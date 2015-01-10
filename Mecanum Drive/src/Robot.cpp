/*
 * Robot.cpp
 *
 *  Created on: Jan 9, 2015
 *      Author: EngTechP7
 */

#include <Robot.h>
#include "Mecanum.h"

Robot::Robot()
{

}

void Robot::init() {
	std::cout << "Robot init";
	drivetrain.disable();
}

void Robot::update() {
	std::cout << "Robot update";
	drivetrain.update();
}

void Robot::disable() {
	std::cout << "Robot disable";
	drivetrain.disable();
}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}

