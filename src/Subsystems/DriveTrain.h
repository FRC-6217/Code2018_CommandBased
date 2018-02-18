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
#include <SmartDashboard/SmartDashboard.h>

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
	//Define which joystick We are using
	bool _secondJoystick;
	// Speed Controller Groups
	SpeedControllerGroup * _leftSide;
	SpeedControllerGroup * _rightSide;

	// Differential Drive Class
	DifferentialDrive * _driveTrain;

	// Sensors
	frc::Encoder * _leftEncoder;
	frc::Encoder * _rightEncoder;
	frc::AnalogInput * _rangeFinder;
	frc::ADXRS450_Gyro * _gyro;

	//Speed of last time
	double lastSpeedOfX = 0;
	double lastSpeedOfY = 0;
	double lastSpeedOfZ = 0;

	//Distance used for encoder

public:
	DriveTrain();
	void InitDefaultCommand();

	bool signbit(double xSignbit);

	void ArcadeDrive(float xDir, float yDir, float zRotation, float XYgovernor, bool squaredInputs);

	void Log();
	void ResetSensors();
	void ResetEncoders();
	double GetEncoderValue();
	double GetREncoderValue();
	void ResetGyro();
	double GetGyroAngle();
	double GetDistance();
	double GetDistanceToObstacle();
	double GetHeading();

};

#endif  // DriveTrain_H
