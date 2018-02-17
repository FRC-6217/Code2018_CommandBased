#ifndef R_LeftSwitch_H
#define R_LeftSwitch_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift.h>

#include <Commands/CommandGroup.h>

class R_LeftSwitch : public CommandGroup {
public:
	R_LeftSwitch();
};

#endif  // R_LeftSwitch_H
