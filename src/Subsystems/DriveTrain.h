#ifndef DriveTrain_H
#define DriveTrain_H

#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre\Phoenix.h"
#include "..\RobotMap.h"

class DriveTrain : public frc::Subsystem {
private:
	// Drive Train Motor Controllers
	WPI_TalonSRX * _victorL1;
	WPI_TalonSRX * _victorL2;
	WPI_TalonSRX * _victorR1;
	WPI_TalonSRX * _victorR2;

	// Speed Controller Groups
	SpeedControllerGroup * _leftSide;
	SpeedControllerGroup * _rightSide;

	// Differential Drive Class
	DifferentialDrive * _driveTrain;

public:
	DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(double xSpeed, double zRotation, bool squaredInputs);

};

#endif  // DriveTrain_H
