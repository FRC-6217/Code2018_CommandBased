#include <pathfinder.h>

int Create3PointTrajectory(double X1, double Y1, double exitAngle1,
							double X2, double Y2, double exitAngle2,
							double X3, double Y3, double exitAngle3){
	int POINT_LENGTH = 3;

	Waypoint *points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

	Waypoint p1 = {X1, Y1, exitAngle1};
	Waypoint p2 = {X2, Y2, exitAngle2};
	Waypoint p3 = {X3, Y3, exitAngle3};

	points[0] = p1;
	points[1] = p2;
	points[2] = p3;

	TrajectoryCandidate candidate;

	// Prepare the Trajectory for Generation.
	//
	// Arguments:
	// Fit Function:        FIT_HERMITE_CUBIC or FIT_HERMITE_QUINTIC
	// Sample Count:        PATHFINDER_SAMPLES_HIGH (100 000)
	//                      PATHFINDER_SAMPLES_LOW  (10 000)
	//                      PATHFINDER_SAMPLES_FAST (1 000)
	// Time Step:           0.001 Seconds
	// Max Velocity:        15 m/s
	// Max Acceleration:    10 m/s/s
	// Max Jerk:            60 m/s/s/s

	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_HIGH, 0.001, 15.0, 10.0, 60.0, &candidate);

	 int length = candidate.length;
	 Segment *trajectory = (Segment*)malloc(length * sizeof(Segment));

	 pathfinder_generate(&candidate, trajectory);

	 Segment *leftTrajectory = (Segment*)malloc(sizeof(Segment) * length);
	 Segment *rightTrajectory = (Segment*)malloc(sizeof(Segment) * length);

	 double wheelbase_width = 0.6;

	 pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);

	 // Do something with the trajectories...

	 free(trajectory);
	 return 0;
}
