/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "R_RightSwitch.h"

R_RightSwitch::R_RightSwitch() {
	//line up directly with switch fence
	AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH_FENCE));//in inches
	AddSequential(new spitOutCube());
	//line Outside the switch fence
	//AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH_OFF_FENCE));//in inches
	//AddSequential(new TurnDegrees(R_TURN_LEFT_DEGREES));//in degrees
	//AddSequential(new DriveDistance(LR_SECOND_DISTANCE_SWITCH_OFF_FENCE));//in inches
	//AddSequential(new spitOutCube());
}
