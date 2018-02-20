#ifndef M_Switch_H
#define M_Switch_H

#include <WPILib.h>

//include Needed Commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/spitOutCube.h"

#include <Commands/CommandGroup.h>

class M_Switch : public CommandGroup {
private:
	int turnDirection;
public:
	M_Switch(std::string scoreSide);
};

#endif  // M_Switch_H
