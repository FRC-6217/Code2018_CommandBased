#ifndef L_LeftScale_H
#define L_LeftScale_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>

#include <Commands/CommandGroup.h>

class L_LeftScale : public CommandGroup {
public:
	L_LeftScale();
};

#endif  // L_LeftScale_H

