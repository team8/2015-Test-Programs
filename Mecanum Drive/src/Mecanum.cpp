#include <WPILib.h>

/**
 * Simplest program to drive a robot with mecanum drive using a single Logitech
 * Extreme 3D Pro joystick and 4 drive motors connected as follows:
 *   - Digital Sidecar 1:
 *     - PWM 1 - Connected to front left drive motor
 *     - PWM 2 - Connected to rear left drive motor
 *     - PWM 3 - Connected to front right drive motor
 *     - PWM 4 - Connected to rear right drive motor
 */
class Mecanum: public IterativeRobot {
private:
	RobotDrive *robotDrive;
	Joystick *driveStick;
	Joystick *turnStick;
public:
	Mecanum();
	void TeleopPeriodic();
	/**
	 * Constructor for this "MecanumDefaultCode" Class.
	 */

};
Mecanum::Mecanum() :
		driveStick(new Joystick((uint32_t) 4)), turnStick(
				new Joystick((uint32_t) 2)) {
	driveStick->SetAxisChannel(Joystick::kTwistAxis, 3);
	robotDrive = new RobotDrive(10, 9, 1, 2);
}
/**
 * Gets called once for each new packet from the DS.
 */
void Mecanum::TeleopPeriodic(void) {
	robotDrive -> MecanumDrive_Cartesian(driveStick->GetX(), driveStick->GetY(),
			turnStick->GetX());
}

START_ROBOT_CLASS(Mecanum);

