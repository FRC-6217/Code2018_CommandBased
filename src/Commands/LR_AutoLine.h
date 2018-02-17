#ifndef LR_AutoLine_H
#define LR_AutoLine_H

#include <WPILib.h>
#include "..\RobotMap.h"

#include "DriveDistance.h"
#include "TurnDegrees.h"
#include "spitOutCube.h"

#include <Commands/CommandGroup.h>

class LR_AutoLine : public CommandGroup {
public:
	LR_AutoLine();
};

#endif  // LR_AutoLine_H
