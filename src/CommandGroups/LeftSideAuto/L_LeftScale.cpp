#include "L_LeftScale.h"

L_LeftScale::L_LeftScale() {
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));
	AddParallel(new AutoLift(LIFTING_TO_SCALE));
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));
	AddSequential(new spitOutCube());

}
