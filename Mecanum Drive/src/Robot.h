/*
 * Robot.h
 *
 *  Created on: Jan 9, 2015
 *      Author: EngTechP7
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include "Mecanum.h"

class Robot {
public:
	Robot();
	virtual ~Robot();

	void init();
	void update();
	void disable();

	Mecanum drivetrain;
	//More subystems here
};

#endif /* SRC_ROBOT_H_ */
