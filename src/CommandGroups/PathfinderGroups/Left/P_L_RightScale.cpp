#include "P_L_RightScale.h"

P_L_RightScale::P_L_RightScale() {
	AddSequential(new Follow3PointTrajectory(P_L_RIGHT_SCALE_X1, P_L_RIGHT_SCALE_Y1, P_L_RIGHT_SCALE_EA1,
					  	  	  	  	  	  	 P_L_RIGHT_SCALE_X2, P_L_RIGHT_SCALE_Y2, P_L_RIGHT_SCALE_EA2,
											 P_L_RIGHT_SCALE_X3, P_L_RIGHT_SCALE_Y3, P_L_RIGHT_SCALE_EA3));
		AddSequential(new DriveDistance(P_LR_OPPOSITE_SCALE_FINAL_DRIVE));
		AddParallel(new AutoLift1(LIFTING_TO_SCALE_UPPER_1, LIFT_UP_DIRECTION));
		AddParallel(new AutoLift2(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
		AddSequential(new spitOutCube());
}
