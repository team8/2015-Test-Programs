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

}

void Arm::disable()
{
	solenoid.Set(DoubleSolenoid::Value::kOff);
	compressor.Stop();
}
