#include <WPILib.h>
#include <iostream>

class Arm : public IterativeRobot
{
	public:
		enum State
		{
			EXTENDING,
			RETRACTING,
			IDLE
		};

		Arm();

		void setState(State state);
		void init();
		void update();
		void disable();

	private:
		Compressor compressor;
		DoubleSolenoid solenoid;

		State state;
};
