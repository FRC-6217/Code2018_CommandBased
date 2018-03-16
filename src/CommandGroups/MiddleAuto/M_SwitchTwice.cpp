/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "M_SwitchTwice.h"

M_SwitchTwice::M_SwitchTwice(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = -1;
		amountOfDistanceOne = 1;
	}
	else if (scoreSide == "R") {
		turnDirection = 1;
		amountOfDistanceOne = 1;
	}
	AddSequential(new DriveDistance(M_DRIVE_OFF_WALL));
	AddSequential(new TurnDegrees(turnDirection * M_SWITCH_ANGLE)); //Turn toward our switch side
	AddSequential(new DriveDistance(amountOfDistanceOne * M_SWITCH_DISTANCE_1)); // Drive to Switch
	AddSequential(new TurnDegrees(-1 * turnDirection * M_SWITCH_ANGLE)); //Align back to straight
	AddSequential(new DriveDistance(M_SWITCH_DISTANCE_2)); // Drive to Switch Wall
	AddSequential(new spitOutCube());

	//Going backwards to line up the the second cube
	AddSequential(new DriveDistance(-M_SWITCH_DISTANCE_2)); // Drive to Switch Wall
	AddSequential(new TurnDegrees(turnDirection * M_SWITCH_ANGLE)); //Align back to straight
	AddSequential(new DriveDistance(-1 * amountOfDistanceOne * M_SWITCH_DISTANCE_1)); // Drive to Switch

	//
}
