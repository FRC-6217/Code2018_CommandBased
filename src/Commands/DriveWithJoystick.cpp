#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(driveTrain);
}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute()
{
	driveTrain->ArcadeDrive(oi->GetDriveStick()->GetThrottle(), oi->GetDriveStick()->GetZ(), true);
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	driveTrain->ArcadeDrive(0, 0, true);
}

void DriveWithJoystick::Interrupted() {
	End();
}
