#ifndef R_RightScale_H
#define R_RightScale_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>

#include <Commands/CommandGroup.h>

class R_RightScale : public CommandGroup {
public:
	R_RightScale();
};

#endif  // R_RightScale_H

