#include "R_RightScale.h"

R_RightScale::R_RightScale() {
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(R_TURN_LEFT_DEGREES));
	AddParallel(new AutoLift1(LIFTING_TO_SCALE, UP_TO_SCALE_DIRECTION));
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));
	AddSequential(new spitOutCube());
}
