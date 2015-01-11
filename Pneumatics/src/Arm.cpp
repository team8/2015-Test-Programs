#include <CompressorThing.cpp>
#include <WPILib.h>
#include <iostream>
#include "SolenoidRobot.cpp"
#include "Arm.h"


void Arm::setState(State state)
{

}

void Arm::disable()
{
	solenoid.Set(DoubleSolenoid::Value::kOff);
	compressor.Stop();
}
