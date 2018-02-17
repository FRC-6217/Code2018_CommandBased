#include "M_LeftAutoLine.h"

M_LeftAutoLine::M_LeftAutoLine() {
	AddSequential(new TurnDegrees(M_AUTO_LINE_ANGLE_L));
	AddSequential(new DriveDistance(M_AUTO_LINE_DISTANCE));
}
