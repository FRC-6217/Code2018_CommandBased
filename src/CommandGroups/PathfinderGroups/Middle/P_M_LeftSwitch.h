#ifndef P_M_LeftSwitch_H
#define P_M_LeftSwitch_H

//include Needed Commands
#include "Commands/Follow3PointTrajectory.h"
#include "Commands/DriveDistance.h"
#include "Commands/spitOutCube.h"


class P_M_LeftSwitch : public CommandGroup {
public:
	P_M_LeftSwitch();
};

#endif  // P_M_LeftSwitch_H
