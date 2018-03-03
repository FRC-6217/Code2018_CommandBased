#include "M_Switch.h"

M_Switch::M_Switch(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = -1;
	}
	else if (scoreSide == "R") {
		turnDirection = 1;
	}
	AddSequential(new DriveDistance(M_DRIVE_OFF_WALL));
	AddSequential(new TurnDegrees(turnDirection * M_SWITCH_ANGLE)); //Turn toward our switch side
	AddSequential(new DriveDistance(M_SWITCH_DISTANCE_1)); // Drive to Switch
	AddSequential(new TurnDegrees(-1 * turnDirection * M_SWITCH_ANGLE)); //Align back to straight
	AddSequential(new DriveDistance(M_SWITCH_DISTANCE_2)); // Drive to Switch Wall
	AddSequential(new spitOutCube());
}
