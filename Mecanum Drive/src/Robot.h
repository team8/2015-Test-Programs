#ifndef ROBOT_H
#define ROBOT_H

#include "Mecanum.h"

class Robot {
public:
	Robot();
	void init();
	void disable();
	void update();

	void move(double linear, double curvy);
private:
	Mecanum *drivetrain;
};

#endif
