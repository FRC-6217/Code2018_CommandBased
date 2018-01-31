#include "DriveTrain.h"
#include "..\CommandBase.h"
#include "../Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
	// Drive Train Motor Controllers
	_victorL1 = new WPI_TalonSRX(VICTOR_SPX_DRIVE_LEFT1);
	_victorL2 = new WPI_TalonSRX(VICTOR_SPX_DRIVE_LEFT2);
	_victorR1 = new WPI_TalonSRX(VICTOR_SPX_DRIVE_RIGHT1);
	_victorR2 = new WPI_TalonSRX(VICTOR_SPX_DRIVE_RIGHT2);

	// Speed Controller Groups
	_leftSide = new SpeedControllerGroup(*_victorL1, *_victorL2);
	_rightSide = new SpeedControllerGroup(*_victorR1, *_victorR2);

	// Differential Drive Class
	_driveTrain = new DifferentialDrive(*_leftSide, *_rightSide);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::ArcadeDrive(double xSpeed, double zRotation, bool squaredInputs){
	_driveTrain->ArcadeDrive(xSpeed, zRotation, squaredInputs);
}
