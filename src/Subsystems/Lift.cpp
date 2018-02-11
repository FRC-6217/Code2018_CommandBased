#include "Lift.h"
#include "..\CommandBase.h"
#include "..\Commands\LiftWithJoystick.h"

Lift::Lift() : frc::Subsystem("Lift") {
	_acmeScrew1 = new Spark(SPARK_ACMESCREW_1);
	_acmeScrew2 = new Spark(SPARK_ACMESCREW_2);
}

void Lift::InitDefaultCommand() {
	SetDefaultCommand(new LiftWithJoystick());
}

void Lift::Lift1Operate(int direction) {
	if(direction == LIFT_DIRECTION_UP) {
		_acmeScrew1->Set(-ACME_SCREW_SPEED);
	}
	else if(direction == LIFT_DIRECTION_DOWN) {
		_acmeScrew1->Set(ACME_SCREW_SPEED);
	}
	else {
		_acmeScrew1->Set(0);
	}
}
void Lift::Lift2Operate(int direction) {
	if(direction == LIFT_DIRECTION_UP) {
		_acmeScrew2->Set(-ACME_SCREW_SPEED);
	}
	else if(direction == LIFT_DIRECTION_DOWN) {
		_acmeScrew2->Set(ACME_SCREW_SPEED);
	}
	else {
		_acmeScrew2->Set(0);
	}
}