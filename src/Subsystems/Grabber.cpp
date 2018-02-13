#include "Grabber.h"
#include "..\CommandBase.h"
#include "../Commands/grabbingWithButtons.h"


Grabber::Grabber() : frc::Subsystem("Grabber") {
	//Grabber Motor controls
	#ifdef SECONDARY_ROBOT
	_leftGrabber = new frc::VictorSP(VICTOR_SP_GRABBER_LEFT);
	_rightGrabber = new frc::VictorSP(VICTOR_SP_GRABBER_RIGHT);
	#endif

	#ifndef SECONDARY_ROBOT
	_leftGrabber = new WPI_VictorSPX(GRABBER_LEFT_SIDE_PORT);
	_rightGrabber = new WPI_VictorSPX(GRABBER_RIGHT_SIDE_PORT);
	#endif
}

void Grabber::InitDefaultCommand() {
	SetDefaultCommand(new grabbingWithButtons());
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
