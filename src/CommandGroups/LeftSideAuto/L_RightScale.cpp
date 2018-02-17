#include "L_RightScale.h"

L_RightScale::L_RightScale() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_LEFT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_THIRD_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_LEFT_DEGREES));

	AddParallel(new AutoLift(LIFTING_TO_SCALE, 0));
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FOURTH_DISTANCE));
	AddSequential(new spitOutCube());
}
