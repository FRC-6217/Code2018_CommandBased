#include "DriveDistance.h"

DriveDistance::DriveDistance(float distanceToDrive) {
	Requires(driveTrain);
	_distanceToDrive = distanceToDrive;
	//SetTimeout(2);
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	driveTrain->ResetEncoders();
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	driveTrain->ArcadeDrive(0.0, -0.50, driveTrain->GetGyroAngle() * KP_GYRO, 0, true);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	//return IsTimedOut();
	return driveTrain->GetEncoderValue() > _distanceToDrive;
}

// Called once after isFinished returns true
void DriveDistance::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
}

void DriveDistance::Interrupted() {
	End();
}
