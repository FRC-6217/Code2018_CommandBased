#ifndef L_RightSwitch_H
#define L_RightSwitch_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>

#include <Commands/CommandGroup.h>

class L_RightSwitch : public CommandGroup {
public:
	L_RightSwitch();
};

#endif  // L_RightSwitch_H
