#include "Grabber.h"


Grabber::Grabber() : frc::Subsystem("Grabber") {
	//Grabber Motor controls
	_leftGrabber = new WPI_VictorSPX(GRABBER_LEFT_SIDE_PORT);
	_rightGrabber = new WPI_VictorSPX(GRABBER_RIGHT_SIDE_PORT);

}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Grabber::RunLeftGrabber(int direction){
	if (direction == GRABBER_IN){
		_leftGrabber->Set(-GRABBER_SPEED);
	}
	else if (direction == GRABBER_OUT){
		_leftGrabber->Set(GRABBER_SPEED);
	}
	else{
		_leftGrabber->Set(0);
	}
}

void Grabber::RunRightGrabber(int direction){
	if (direction == GRABBER_IN){
		_rightGrabber->Set(GRABBER_SPEED);
	}
	else if (direction == GRABBER_OUT){
		_rightGrabber->Set(-GRABBER_SPEED);
	}
	else{
		_rightGrabber->Set(0);
	}
}

void Grabber::RunGrabber(int direction){
	Grabber::RunLeftGrabber(direction);
	Grabber::RunRightGrabber(direction);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
