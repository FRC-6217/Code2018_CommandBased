#ifndef P_R_LeftScale_H
#define P_R_LeftScale_H

#include "Commands/Follow3PointTrajectory.h"
#include "Commands/DriveDistance.h"
#include "Commands/AutoLift1.h"
#include "Commands/AutoLift2.h"
#include "Commands/spitOutCube.h"

class P_R_LeftScale : public CommandGroup {
public:
	P_R_LeftScale();
};

#endif  // P_R_LeftScale_H
