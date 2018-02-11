#ifndef DriveTrain_H
#define DriveTrain_H

#include <AnalogGyro.h>
#include <AnalogInput.h>
#include <Encoder.h>
#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre\Phoenix.h"
#include "..\RobotMap.h"

class DriveTrain : public frc::Subsystem {
private:
	// Drive Train Motor Controllers
#ifdef SECONDARY_ROBOT
	frc::VictorSP* _victorL1;
	frc::VictorSP* _victorL2;
	frc::VictorSP* _victorR1;
	frc::VictorSP* _victorR2;
#endif
#ifndef SECONDARY_ROBOT
	WPI_VictorSPX* _victorL1;
	WPI_VictorSPX* _victorL2;
	WPI_VictorSPX* _victorR1;
	WPI_VictorSPX* _victorR2;
#endif

	// Speed Controller Groups
	SpeedControllerGroup * _leftSide;
	SpeedControllerGroup * _rightSide;

	// Differential Drive Class
	DifferentialDrive * _driveTrain;

	// Sensors
	frc::Encoder * _leftEncoder;
	frc::Encoder * _rightEncoder;
	frc::AnalogInput * _rangeFinder;
	frc::AnalogGyro * _gyro;

	//Speed of last time
	double lastSpeedOfX = 0;
	double lastSpeedOfY = 0;
	double lastSpeedOfZ = 0;

public:
	DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(float xDir, float yDir, float zRotation, float governor, bool squaredInputs);
	void Log();
	void ResetSensors();
	void ResetEncoders();
	void ResetGyro();
	double GetDistance();
	double GetDistanceToObstacle();
	double GetHeading();

};

#endif  // DriveTrain_H
