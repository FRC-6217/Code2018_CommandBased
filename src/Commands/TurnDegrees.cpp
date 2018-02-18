/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "TurnDegrees.h"



TurnDegrees::TurnDegrees(float turnDegrees) {
	Requires(driveTrain);
	_turnDegrees = turnDegrees;
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
	if (driveTrain->signbit(_turnDegrees)){
		driveTrain->ArcadeDrive(0.45, 0, 0.45, 0, true);
	}
	else {
		driveTrain->ArcadeDrive(-0.45, 0, -0.45, 0, true);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {
	return (fabs(driveTrain->GetGyroAngle()) > fabs(_turnDegrees));
}

// Called once after isFinished returns true
void TurnDegrees::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {
	End();
}
