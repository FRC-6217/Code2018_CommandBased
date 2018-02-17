/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "L_RightSwitch.h"

L_RightSwitch::L_RightSwitch() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_THIRD_DISTANCE));
}
