#include <Arm.h>
#include <WPILib.h>
#include <iostream>

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
			break;
		case RETRACTING:
			compressor.Start();
			solenoid.Set(DoubleSolenoid::Value::kReverse);
			break;
		case IDLE:
			compressor.Stop();
			solenoid.Set(DoubleSolenoid::Value::kOff);
			break;
	}
}

void Arm::init()
{
	setState(IDLE);
}
