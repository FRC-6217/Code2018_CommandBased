#include "L_LeftScale.h"

L_LeftScale::L_LeftScale() {
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_SCALE_DEGREES));
	//AddParallel(new AutoLift());
	//once added a command called AutoLift uncomment the line above this one
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));
	AddSequential(new spitOutCube());

}
