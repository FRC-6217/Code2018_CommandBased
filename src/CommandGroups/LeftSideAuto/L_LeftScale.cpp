#include "L_LeftScale.h"

L_LeftScale::L_LeftScale() {
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));
	AddParallel(new AutoLift1(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));
	AddSequential(new spitOutCube());

}
