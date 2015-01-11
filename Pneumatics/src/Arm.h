#include <WPILib.h>
#include <iostream>
#include "SolenoidRobot.cpp"
#include "CompressorThing.cpp"

class Arm : public IterativeRobot
{
	private:
		Compressor compressor;
		DoubleSolenoid solenoid;

		typedef enum State
		{
			EXTENDING,
			RETRACTING,
			IDLE
		} State;

		State state;

	public:
		Arm();
		void setState(State state);
		void init();
		void update();
		void disable();
};
