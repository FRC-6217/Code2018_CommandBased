#ifndef M_LeftAutoLine_H
#define M_LeftAutoLine_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>

#include <Commands/CommandGroup.h>

class M_LeftAutoLine : public CommandGroup {
public:
	M_LeftAutoLine();
};

#endif  // M_LeftAutoLine_H
