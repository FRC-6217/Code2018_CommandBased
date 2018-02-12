#include "DriveDistance.h"

DriveDistance::DriveDistance() {
	Requires(driveTrain);
	SetTimeout(1);
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	driveTrain->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	driveTrain->ArcadeDrive(0.0, -0.5, 0, 0, true);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveDistance::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
}

void DriveDistance::Interrupted() {
	End();
}
