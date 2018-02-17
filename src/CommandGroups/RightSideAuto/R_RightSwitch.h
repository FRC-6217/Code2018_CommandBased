#ifndef R_RightSwitch_H
#define R_RightSwitch_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>


#include <Commands/CommandGroup.h>

class R_RightSwitch : public CommandGroup {
public:
	R_RightSwitch();
};

#endif  // R_RightSwitch_H
