#include <Path_Finder.cpp>
#include "Follow3PointTrajectory.h"

Follow3PointTrajectory::Follow3PointTrajectory(double X1, double Y1, double exitAngle1,
		 	 	 	 	 	 	 	 	 	   double X2, double Y2, double exitAngle2,
											   double X3, double Y3, double exitAngle3) {
	Requires(driveTrain);
	SetTimeout(15);
	_X1 = X1;
	_Y1 = Y1;
	_exitAngle1 = exitAngle1;
	_X2 = X2;
	_Y2 = Y2;
	_exitAngle2 = exitAngle2;
	_X3 = X3;
	_Y3 = Y3;
	_exitAngle3 = exitAngle3;

	pf = new Pathfinder;
	lPower = 0;
	rPower = 0;

	_returnValue[0] = 0.0;
	_returnValue[1] = 0.0;
}

// Called just before this Command runs the first time
void Follow3PointTrajectory::Initialize() {
	pf->Gen3PointTrajectory(_X1, _Y1, _exitAngle1, _X2, _Y2, _exitAngle2, _X3, _Y3, _exitAngle3);
	pf->ConfigureEncoders();
}

// Called repeatedly when this Command is scheduled to run
void Follow3PointTrajectory::Execute() {
	pf->FollowTrajectory(driveTrain->GetLEncoderValue(), driveTrain->GetREncoderValue(), driveTrain->GetGyroAngle(), _returnValue);
	lPower = _returnValue[0];
	rPower = _returnValue[1];

	driveTrain->TankDrive(lPower, rPower);
}

// Make this return true when this Command no longer needs to run execute()
bool Follow3PointTrajectory::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Follow3PointTrajectory::End() {
	driveTrain->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Follow3PointTrajectory::Interrupted() {
	End();
}
