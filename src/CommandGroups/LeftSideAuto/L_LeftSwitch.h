#ifndef L_LeftSwitch_H
#define L_LeftSwitch_H

#include <WPILib.h>

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>


#include <Commands/CommandGroup.h>

class L_LeftSwitch : public CommandGroup {
public:
	L_LeftSwitch();
};

#endif  // L_LeftSwitch_H
