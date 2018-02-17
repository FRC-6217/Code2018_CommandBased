#ifndef L_RightSwitch_H
#define L_RightSwitch_H

#include <WPILib.h>

#include "DriveDistance.h"
#include "TurnDegrees.h"
#include "spitOutCube.h"
#include "AutoLift.h"

#include <Commands/CommandGroup.h>

class L_RightSwitch : public CommandGroup {
public:
	L_RightSwitch();
};

#endif  // L_RightSwitch_H
