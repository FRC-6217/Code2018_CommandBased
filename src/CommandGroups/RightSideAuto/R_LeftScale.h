#ifndef R_LeftScale_H
#define R_LeftScale_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift.h>

#include <Commands/CommandGroup.h>

class R_LeftScale : public CommandGroup {
public:
	R_LeftScale();
};

#endif  // R_LeftScale_H
