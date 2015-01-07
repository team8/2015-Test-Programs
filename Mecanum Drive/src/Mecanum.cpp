#include "WPILib.h"/**
 * Simplest program to drive a robot with mecanum drive using a single Logitech
 * Extreme 3D Pro joystick and 4 drive motors connected as follows:
 *   - Digital Sidecar 1:
 *     - PWM 1 - Connected to front left drive motor
 *     - PWM 2 - Connected to rear left drive motor
 *     - PWM 3 - Connected to front right drive motor
 *     - PWM 4 - Connected to rear right drive motor
 */

Mecanum::Mecanum() :
//Replace with actual port numbers of the talons
	leftFront( (uint32_t) 5),
	leftBack( (uint32_t) 1),
	rightFront( (uint32_t) 6),
	rightBack( (uint32_t) 2)
{

}

void Mecanum::init() {
	state = ON;
}

void Mecanum::disable() {
	state = OFF;
}

void Mecanum::update() {
	switch(state) {
	case ON:
		break;
	case OFF:
		leftFront.Set(0);
		leftBack.Set(0);
		rightFront.Set(0);
		rightBack.Set(0);
	}
}
