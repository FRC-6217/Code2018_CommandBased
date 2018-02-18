#include "grabbingWithButtons.h"

grabbingWithButtons::grabbingWithButtons() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void grabbingWithButtons::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void grabbingWithButtons::Execute() {
	if (oi->GetGameController()->GetRawButton(GRABBER_IN_BUTTON) == 1){
		currentDirection = GRABBER_IN;
	}
	else if (oi->GetGameController()->GetRawButton(GRABBER_OUT_BUTTON) == 1){
		currentDirection = GRABBER_OUT;
	}
	else if(oi->GetGameController()->GetRawButton(GRABBER_STOP_BUTTON) == 1){
		currentDirection = GRABBER_STOP;
	}
	if (currentDirection == GRABBER_STOP){
		if (oi->GetGameController()->GetRawAxis(GRABBER_LEFT_SIDE_AXIS) >= .25){
			grabber->RunLeftGrabber(GRABBER_OUT);
		}
		else if (oi->GetGameController()->GetRawAxis(GRABBER_LEFT_SIDE_AXIS) <= -.25){
			grabber->RunLeftGrabber(GRABBER_IN);
		}
		else{
			grabber->RunLeftGrabber(GRABBER_STOP);
		}

		if (oi->GetGameController()->GetRawAxis(GRABBER_RIGHT_SIDE_AXIS) >= .25){
			grabber->RunRightGrabber(GRABBER_OUT);
		}
		else if (oi->GetGameController()->GetRawAxis(GRABBER_RIGHT_SIDE_AXIS) <= -.25){
			grabber->RunRightGrabber(GRABBER_IN);
		}
		else{
			grabber->RunRightGrabber(GRABBER_STOP);
		}
	}
	else{
		grabber->RunGrabber(currentDirection);
	}
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
