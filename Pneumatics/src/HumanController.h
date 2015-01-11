#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include <WPILib.h>
#include "Robot.h"
#include <stdlib.h>
#include <iostream>

class HumanController
{
	private:
  		Robot *robot;

  		Joystick operatorController;
	public:

		HumanController(Robot *robot);

		void update();
};
#endif
