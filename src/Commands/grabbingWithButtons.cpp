#include "grabbingWithButtons.h"

grabbingWithButtons::grabbingWithButtons() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void grabbingWithButtons::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void grabbingWithButtons::Execute() {
	int directionOfGrabber;
	if (oi->GetGameStick()->GetRawButton(GRABBER_IN_BUTTON) == 1){
			directionOfGrabber = GRABBER_IN;
	}
	else if (oi->GetGameStick()->GetRawButton(GRABBER_OUT_BUTTON) == 1){
			directionOfGrabber = GRABBER_OUT;
	}
	else{
		directionOfGrabber = GRABBER_STOP;
	}
	grabber->RunGrabber(directionOfGrabber);
}

// Make this return true when this Command no longer needs to run execute()
bool grabbingWithButtons::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void grabbingWithButtons::End() {
	grabber->RunGrabber(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void grabbingWithButtons::Interrupted() {
	End();
}
