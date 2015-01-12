#ifndef ROBOT_H
#define ROBOT_H
#include <Arm.h>
#include <WPILib.h>
#include "Constants.h"

class Robot
{
	private:
		Arm arm;

	public:
		Robot();

		void init();
		void update();
		void disable();

		void setArmState(Arm::State state);
};

#endif
