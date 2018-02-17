#include "L_LeftScale.h"

L_LeftScale::L_LeftScale() {
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_SCALE_DEGREES));
	AddSequential(new DriveDistance(LR_SCALE_SECOND_DISTANCE));


}