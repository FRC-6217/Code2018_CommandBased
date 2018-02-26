#include "LR_SideScale.h"

LR_SideScale::LR_SideScale(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = -1;
	}
	else if (scoreSide == "R") {
		turnDirection = 1;
	}

	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(turnDirection * TURN_90_DEGREES));
	AddParallel(new AutoLift2(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));
	AddParallel(new AutoLift1(LIFTING_TO_SCALE_UPPER_1, LIFT_UP_DIRECTION));
	AddSequential(new spitOutCube());
}