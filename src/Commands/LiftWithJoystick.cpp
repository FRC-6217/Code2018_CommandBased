#include "LiftWithJoystick.h"

LiftWithJoystick::LiftWithJoystick() {
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftWithJoystick::Execute() {
	int lift1Direction = LIFT_DIRECTION_STOP;
	int lift2Direction = LIFT_DIRECTION_STOP;
	double lift1Down = oi->GetGameController()->GetRawAxis(LIFT_1_DOWN);
	double lift2Down = oi->GetGameController()->GetRawAxis(LIFT_2_DOWN);
	frc::SmartDashboard::PutNumber("Lift 1 down percent", lift1Down);
	frc::SmartDashboard::PutNumber("Lift 2 down percent", lift2Down);
	//Determine Lift1 Direction based off buttons
	if(oi->GetGameController()->GetRawButton(LIFT_1_UP) == 1) {
		lift1Direction = LIFT_DIRECTION_UP;
	}
	else if(lift1Down >= TRIGGER_PERCENT_PRESS) {
		lift1Direction = LIFT_DIRECTION_DOWN;
	}

	lift->Lift1Operate(lift1Direction);

	//Determine Lift2 Direction based off buttons
	if(oi->GetGameController()->GetRawButton(LIFT_2_UP) == 1) {
		lift2Direction = LIFT_DIRECTION_UP;
	}
	else if(lift2Down >= TRIGGER_PERCENT_PRESS) {
		lift2Direction = LIFT_DIRECTION_DOWN;
	}
	lift->Lift2Operate(lift2Direction);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftWithJoystick::End() {
	lift->Lift1Operate(LIFT_DIRECTION_STOP);
	lift->Lift2Operate(LIFT_DIRECTION_STOP);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftWithJoystick::Interrupted() {
	End();
}
