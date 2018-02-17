#ifndef LR_AutoLine_H
#define LR_AutoLine_H

#include <WPILib.h>
#include "..\RobotMap.h"

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>

#include <Commands/CommandGroup.h>

class LR_AutoLine : public CommandGroup {
public:
	LR_AutoLine();
};

#endif  // LR_AutoLine_H
