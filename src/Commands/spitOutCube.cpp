#include "spitOutCube.h"

spitOutCube::spitOutCube() {
	Requires(grabber);

}

// Called just before this Command runs the first time
void spitOutCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void spitOutCube::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool spitOutCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void spitOutCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void spitOutCube::Interrupted() {

}
