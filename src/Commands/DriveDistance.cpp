#include "DriveDistance.h"

DriveDistance::DriveDistance(float distanceToDrive) {
	Requires(driveTrain);
	_distanceToDrive = distanceToDrive;
	SetTimeout(_distanceToDrive/20);
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	frc::SmartDashboard::PutString("Command Message", "Drive Distance Start");
	driveTrain->ResetEncoders();
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	driveTrain->ArcadeDrive(0.0, DRIVE_DISTANCE_SPEED, driveTrain->GetGyroAngle() * KP_GYRO, 0, true);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return driveTrain->GetEncoderValue() > _distanceToDrive || IsTimedOut();
}

// Called once after isFinished returns true
void DriveDistance::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
	frc::SmartDashboard::PutString("Command Message", "Drive Distance Stop");
}

void DriveDistance::Interrupted() {
	End();
}
