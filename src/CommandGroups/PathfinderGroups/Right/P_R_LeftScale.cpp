#include "P_R_LeftScale.h"

P_R_LeftScale::P_R_LeftScale() {
	AddSequential(new Follow3PointTrajectory(P_R_LEFT_SCALE_X1, P_R_LEFT_SCALE_Y1, P_R_LEFT_SCALE_EA1,
						  	  	  	  	  	 P_R_LEFT_SCALE_X2, P_R_LEFT_SCALE_Y2, P_R_LEFT_SCALE_EA2,
											 P_R_LEFT_SCALE_X3, P_R_LEFT_SCALE_Y3, P_R_LEFT_SCALE_EA3));
		AddSequential(new DriveDistance(P_LR_OPPOSITE_SCALE_FINAL_DRIVE));
		AddParallel(new AutoLift1(LIFTING_TO_SCALE_UPPER_1, LIFT_UP_DIRECTION));
		AddParallel(new AutoLift2(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
		AddSequential(new spitOutCube());
}
