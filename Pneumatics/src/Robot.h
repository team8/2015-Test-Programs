#ifndef ROBOT_H
#define ROBOT_H
#include <WPILib.h>
#include "Constants.h"
#include "Arm.h"

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
