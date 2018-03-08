#include "P_M_LeftSwitch.h"

P_M_LeftSwitch::P_M_LeftSwitch() {
	AddSequential(new Follow3PointTrajectory(P_M_LEFT_SWITCH_X1, P_M_LEFT_SWITCH_Y1, P_M_LEFT_SWITCH_EA1,
					  	  	  	  	  	  	 P_M_LEFT_SWITCH_X2, P_M_LEFT_SWITCH_Y2, P_M_LEFT_SWITCH_EA2,
											 P_M_LEFT_SWITCH_X3, P_M_LEFT_SWITCH_Y3, P_M_LEFT_SWITCH_EA3));
	AddSequential(new DriveDistance(M_LR_SWITCH_FINAL_DRIVE)); // Drive to Switch Wall
	AddSequential(new spitOutCube());
}
