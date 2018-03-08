#ifndef P_R_LeftSwitch_H
#define P_R_LeftSwitch_H

#include "Commands/Follow3PointTrajectory.h"
#include "Commands/DriveDistance.h"
#include "Commands/spitOutCube.h"

class P_R_LeftSwitch : public CommandGroup {
public:
	P_R_LeftSwitch();
};

#endif  // P_R_LeftSwitch_H
