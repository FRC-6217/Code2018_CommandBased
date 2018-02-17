#include <Commands/L_LeftSwitch.h>

L_LeftSwitch::L_LeftSwitch() {
	AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH));//in inches
	AddSequential(new TurnDegrees(LR_DEGREES_SWITCH));//in degrees
	AddSequential(new DriveDistance(LR_SECOND_DISTANCE_SWITCH));//in inches
	AddSequential(new spitOutCube());
}
