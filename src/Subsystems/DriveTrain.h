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
	WPI_VictorSPX* _victorL1;
	WPI_VictorSPX* _victorL2;
	WPI_VictorSPX* _victorR1;
	WPI_VictorSPX* _victorR2;

	// Speed Controller Groups
	SpeedControllerGroup * _leftSide;
	SpeedControllerGroup * _rightSide;

	// Differential Drive Class
	DifferentialDrive * _driveTrain;

public:
	DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(float xDir, float yDir, float zRotation, float governor, bool squaredInputs);

};

#endif  // DriveTrain_H
