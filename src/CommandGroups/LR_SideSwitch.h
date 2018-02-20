#ifndef LR_SideSwitch_H
#define LR_SideSwitch_H

#include <WPILib.h>

//include Needed Commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/spitOutCube.h"


#include <Commands/CommandGroup.h>
class LR_SideSwitch : public CommandGroup {
private:
	int turnDirection;
public:
	LR_SideSwitch(char scoreSide);
};

#endif  // LR_SideSwitch_H
