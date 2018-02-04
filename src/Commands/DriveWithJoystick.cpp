#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(driveTrain);
}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute()
{
	driveTrain->ArcadeDrive(oi->GetDriveStick()->GetX(), oi->GetDriveStick()->GetY(), oi->GetDriveStick()->GetZ(), oi->GetDriveStick()->GetRawAxis(DRIVE_GOVERNOR_NUMBER), true);
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
}

void DriveWithJoystick::Interrupted() {
	End();
}
