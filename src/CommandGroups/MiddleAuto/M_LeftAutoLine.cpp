#include "M_RightAutoLine.h"

M_RightAutoLine::M_RightAutoLine() {
	AddSequential(new TurnDegrees(M_AUTO_LINE_ANGLE_L));
	AddSequential(new DriveDistance(M_AUTO_LINE_DISTANCE));
}
