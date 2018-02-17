#include "L_RightScale.h"

L_RightScale::L_RightScale() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_OPPOSITE_SCALE_FIRST_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(L_OPPOSITE_SCALE_SECOND_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_THIRD_DISTANCE));
	AddSequential(new TurnDegrees(L_OPPOSITE_SCALE_THIRD_DEGREES));

	AddParallel(new AutoLift());
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FOURTH_DISTANCE));
	AddSequential(new spitOutCube());
}
