#ifndef M_RightAutoLine_H
#define M_RightAutoLine_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>

#include <Commands/CommandGroup.h>

class M_RightAutoLine : public CommandGroup {
public:
	M_RightAutoLine();
};

#endif  // M_RightAutoLine_H
