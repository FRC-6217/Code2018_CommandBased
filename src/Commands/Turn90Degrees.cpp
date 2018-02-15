/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "Turn90Degrees.h"



Turn90Degrees::Turn90Degrees() {
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void Turn90Degrees::Initialize() {
	driveTrain->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void Turn90Degrees::Execute() {
	driveTrain->ArcadeDrive(0 ,0 ,.75 ,0 ,true);
}

// Make this return true when this Command no longer needs to run execute()
bool Turn90Degrees::IsFinished() {
	return (driveTrain->GetGyroAngle() > -45.0);
}

// Called once after isFinished returns true
void Turn90Degrees::End() {
	driveTrain->ArcadeDrive(0 ,0 ,0 ,0 ,true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn90Degrees::Interrupted() {
	End();
}
