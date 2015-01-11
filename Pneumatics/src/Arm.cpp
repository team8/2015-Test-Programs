#include <WPILib.h>
#include <iostream>
#include "Arm.h"

Arm::Arm():
	compressor((uint32_t) 0),
	solenoid((uint32_t) 0, (uint32_t) 0)
{
	setState(IDLE);
}

void Arm::setState(State state)
{
	this -> state = state;
}

void Arm::disable()
{
	setState(IDLE);
}

void Arm::update()
{
	switch(state)
	{
		case EXTENDING: 
			compressor.Start();
			solenoid.Set(DoubleSolenoid::Value::kForward);
		case RETRACTING:
			compressor.Start();
			solenoid.Set(DoubleSolenoid::Value::kReverse);
		case: IDLE
			compressor.Stop();
			solenoid.Set(DoubleSolenoid::Value::kOff);
	}
	
}

void Arm::init()
{
	setState(IDLE);
}
