#include "P_R_LeftSwitch.h"

P_R_LeftSwitch::P_R_LeftSwitch() {
	AddSequential(new Follow3PointTrajectory(P_R_LEFT_SWITCH_X1, P_R_LEFT_SWITCH_Y1, P_R_LEFT_SWITCH_EA1,
				  	  	  	  	  	  	  	 P_R_LEFT_SWITCH_X2, P_R_LEFT_SWITCH_Y2, P_R_LEFT_SWITCH_EA2,
											 P_R_LEFT_SWITCH_X3, P_R_LEFT_SWITCH_Y3, P_R_LEFT_SWITCH_EA3));
	AddSequential(new DriveDistance(P_LR_OPPOSITE_SWITCH_FINAL_DRIVE));
	AddSequential(new spitOutCube());
}
