#include "L_LeftSwitch.h"

L_LeftSwitch::L_LeftSwitch() {
	//line up directly with switch fence
	AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH_FENCE));//in inches
	AddSequential(new spitOutCube());
	//line Outside the switch fence
	//AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH_OFF_FENCE));//in inches
	//AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));//in degrees
	//AddSequential(new DriveDistance(LR_SECOND_DISTANCE_SWITCH_OFF_FENCE));//in inches
	//AddSequential(new spitOutCube());
}
