#ifndef P_L_RightScale_H
#define P_L_RightScale_H

#include "Commands/Follow3PointTrajectory.h"
#include "Commands/DriveDistance.h"
#include "Commands/AutoLift1.h"
#include "Commands/AutoLift2.h"
#include "Commands/spitOutCube.h"


class P_L_RightScale : public CommandGroup {
public:
	P_L_RightScale();
};

#endif  // P_L_RightScale_H
