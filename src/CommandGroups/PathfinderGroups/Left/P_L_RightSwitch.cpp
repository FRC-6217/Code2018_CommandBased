#include "P_L_RightSwitch.h"

P_L_RightSwitch::P_L_RightSwitch() {
	AddSequential(new Follow3PointTrajectory(P_L_RIGHT_SWITCH_X1, P_L_RIGHT_SWITCH_Y1, P_L_RIGHT_SWITCH_EA1,
				  	  	  	  	  	  	  	 P_L_RIGHT_SWITCH_X2, P_L_RIGHT_SWITCH_Y2, P_L_RIGHT_SWITCH_EA2,
											 P_L_RIGHT_SWITCH_X3, P_L_RIGHT_SWITCH_Y3, P_L_RIGHT_SWITCH_EA3));
	AddSequential(new DriveDistance(P_LR_OPPOSITE_SWITCH_FINAL_DRIVE));
	AddSequential(new spitOutCube());
}
