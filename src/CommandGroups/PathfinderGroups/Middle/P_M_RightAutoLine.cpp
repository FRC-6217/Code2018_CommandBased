#include "P_M_RightAutoLine.h"

P_M_RightAutoLine::P_M_RightAutoLine() {
	AddSequential(new Follow3PointTrajectory(P_M_RIGHT_AUTO_LINE_X1, P_M_RIGHT_AUTO_LINE_Y1, P_M_RIGHT_AUTO_LINE_EA1,
					  	  	  	  	  	  	 P_M_RIGHT_AUTO_LINE_X2, P_M_RIGHT_AUTO_LINE_Y2, P_M_RIGHT_AUTO_LINE_EA2,
											 P_M_RIGHT_AUTO_LINE_X3, P_M_RIGHT_AUTO_LINE_Y3, P_M_RIGHT_AUTO_LINE_EA3));
}
