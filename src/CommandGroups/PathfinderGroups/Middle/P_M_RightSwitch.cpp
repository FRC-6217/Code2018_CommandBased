/*#include "P_M_RightSwitch.h"

P_M_RightSwitch::P_M_RightSwitch() {
	AddSequential(new Follow3PointTrajectory(P_M_RIGHT_SWITCH_X1, P_M_RIGHT_SWITCH_Y1, P_M_RIGHT_SWITCH_EA1,
						  	  	  	  	  	 P_M_RIGHT_SWITCH_X2, P_M_RIGHT_SWITCH_Y2, P_M_RIGHT_SWITCH_EA2,
											 P_M_RIGHT_SWITCH_X3, P_M_RIGHT_SWITCH_Y3, P_M_RIGHT_SWITCH_EA3));
	AddSequential(new DriveDistance(M_LR_SWITCH_FINAL_DRIVE)); // Drive to Switch Wall
	AddParallel(new AutoLift1(LIFTING_TO_SWITCH_UPPER_1, LIFT_UP_DIRECTION));
	AddSequential(new spitOutCube());
}
*/
