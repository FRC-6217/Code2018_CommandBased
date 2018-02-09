#include "DriveTrain.h"
#include "..\CommandBase.h"
#include "../Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
	// Drive Train Motor Controllers
	_victorL1 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_LEFT1);
	_victorL2 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_LEFT2);
	_victorR1 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_RIGHT1);
	_victorR2 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_RIGHT2);

	// Speed Controller Groups
	_leftSide = new SpeedControllerGroup(*_victorL1, *_victorL2);
	_rightSide = new SpeedControllerGroup(*_victorR1, *_victorR2);

	// Differential Drive Class
	_driveTrain = new DifferentialDrive(*_leftSide, *_rightSide);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::ArcadeDrive(float xDir, float yDir, float zRotation, float governor, bool squaredInputs){
	//Dead zone
	zRotation = fabs(zRotation) > 0.15 ? zRotation : 0.0;
	yDir = fabs(yDir) > 0.1 ? yDir : 0.0;
	//Use governor to limit speed, governor paddle on joystick - down is 0%, up is 100%
	xDir *= (1 - governor);
	yDir *= (1 - governor);

	// Drive Robot
	_driveTrain->ArcadeDrive(-yDir, zRotation, squaredInputs);
}
