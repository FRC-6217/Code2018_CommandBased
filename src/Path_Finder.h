/*#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <pathfinder.h>
#include "RobotMap.h"

class Pathfinder {
public:
	void Gen3PointTrajectory(double X1, double Y1, double exitAngle1,
							 double X2, double Y2, double exitAngle2,
							 double X3, double Y3, double exitAngle3);
	void ConfigureEncoders();
	void FollowTrajectory(double lEncoder, double rEncoder, double gryo, double returnValue[2]);
	Pathfinder();

private:
	int length;
	Segment *leftTrajectory;
	Segment *rightTrajectory;
	EncoderConfig leftConfig;
	EncoderConfig rightConfig;
};

Pathfinder::Pathfinder() : leftConfig(), rightConfig() {
	length = 0;
	leftTrajectory = new Segment;
	rightTrajectory = new Segment;
}

void Pathfinder::Gen3PointTrajectory(double X1, double Y1, double exitAngle1,
									 double X2, double Y2, double exitAngle2,
									 double X3, double Y3, double exitAngle3) {
	int POINT_LENGTH = 3;

	Waypoint *points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

	Waypoint p1 = {X1, Y1, d2r(exitAngle1)};
	Waypoint p2 = {X2, Y2, d2r(exitAngle2)};
	Waypoint p3 = {X3, Y3, d2r(exitAngle3)};

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

	double wheelbase_width = WHEEL_BASE_WIDTH; //distance between left and right wheels meters

	pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);

	free(points);
	free(trajectory);
	free(leftTrajectory);
	free(rightTrajectory);
}

void Pathfinder::ConfigureEncoders() {
	EncoderConfig leftConfig = { INITIAL_POSITION, TICKS_PER_REVOLUTION,
								 WHEEL_CIRCUMFRENCE, KP, KI, KD, KV, KA};

	EncoderConfig rightConfig = { INITIAL_POSITION, TICKS_PER_REVOLUTION,
								  WHEEL_CIRCUMFRENCE, KP, KI, KD, KV, KA};

}

void Pathfinder::FollowTrajectory(double lEncoder, double rEncoder, double gyro, double returnValue[2]) {

	EncoderFollower* leftFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	leftFollower->last_error = 0; leftFollower->segment = 0; leftFollower->finished = 0;

	EncoderFollower* rightFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	rightFollower->last_error = 0; rightFollower->segment = 0; rightFollower->finished = 0;

	// Arg 1: The EncoderConfig
	// Arg 2: The EncoderFollower for this side
	// Arg 3: The Trajectory generated from `pathfinder_modify_tank`
	// Arg 4: The Length of the Trajectory (length used in Segment seg[length];)
	// Arg 5: The current value of your encoder
	double l = pathfinder_follow_encoder(leftConfig, leftFollower, leftTrajectory, length, lEncoder);
	double r = pathfinder_follow_encoder(rightConfig, rightFollower, rightTrajectory, length, rEncoder);

	double gyro_heading = gyro;
	double desired_heading = r2d(leftFollower->heading);

	double angle_difference = desired_heading - gyro_heading;    // Make sure to bound this from -180 to 180, otherwise you will get super large values

	double turn = 0.8 * (-1.0/180.0) * angle_difference;

	returnValue[0] = (l + turn);
	returnValue[1] = (r - turn);

	free(leftFollower);
	free(rightFollower);
}

#endif //PATH_FINDER_H
*/
