#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <algorithm>
#include "WPILib.h"

class Mecanum {
public:
	Mecanum();
	void init();
	void disable();
	void update();
	void meep(double linear, double curvy);
	void set();
private:
	Talon leftFront;
	Talon leftBack;
	Talon rightFront;
	Talon rightBack;

	double linear;
	double curvy;
	double leftSpeed;
	double rightSpeed;

	enum State {ON, OFF} state;
};

#endif
