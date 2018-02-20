#include "LR_SideSwitch.h"

LR_SideSwitch::LR_SideSwitch(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = -1;
	}
	else if (scoreSide == "R") {
		turnDirection = 1;
	}

	AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH));//in inches
	AddSequential(new TurnDegrees(turnDirection * TURN_90_DEGREES));//in degrees
	AddSequential(new DriveDistance(LR_SECOND_DISTANCE_SWITCH));//in inches
	AddSequential(new spitOutCube());
	}
