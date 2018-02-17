/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <TimedRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/DriveDistance.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/Auto1.h"
#include "CommandBase.h"
#include "ctre\Phoenix.h"

#include "WeekZero.h"

class Robot : public frc::TimedRobot {
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::CommandGroup* _autoCommandGroup = nullptr;
	frc::SendableChooser<std::string> _chooserStartingPosition;
	frc::SendableChooser<std::string> _chooserPriorityGoal;
	frc::SendableChooser<std::string> _chooserCrossField;
public:

	void RobotInit() override {
		CommandBase::init();

		// Build Autonomous Mode Choices on Smart Dashboard
		_chooserStartingPosition.AddObject("Left", "L");
		_chooserStartingPosition.AddDefault("Middle", "M");
		_chooserStartingPosition.AddObject("Right", "R");
		frc::SmartDashboard::PutData("Starting Position", &_chooserStartingPosition);
		_chooserPriorityGoal.AddDefault("Switch", "W");
		_chooserPriorityGoal.AddObject("Scale", "C");
		_chooserPriorityGoal.AddObject("Auto Line", "A");
		frc::SmartDashboard::PutData("Goal Priority", &_chooserPriorityGoal);
		_chooserCrossField.AddDefault("No", "N");
		_chooserCrossField.AddObject("Yes", "Y");
		frc::SmartDashboard::PutData("Cross field for Goal", &_chooserCrossField);

		// Add Command Based Scheduler Status to dashboard
		frc::SmartDashboard::PutData(frc::Scheduler::GetInstance());
		// Add test commands on Smart Dashboard
		frc::SmartDashboard::PutData("Test Auto 1", new Auto1());
		frc::SmartDashboard::PutData("Drive 20 inches", new DriveDistance(10));
		frc::SmartDashboard::PutData("Turn 90 degrees", new TurnDegrees(90));
	}

	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() override {
		std::string gameData;
		std::string startingPosition;
		std::string priorityGoal;
		std::string crossField;
		std::string autoModeOptions;

		startingPosition = _chooserStartingPosition.GetSelected();
		priorityGoal = _chooserPriorityGoal.GetSelected();
		crossField = _chooserCrossField.GetSelected();

		// Game data - for 2018 three characters indicating position of switch and scale (e.g. LRL)
		//gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		gameData = WeekZero::getGameSpecificMessage();
		// Default game data
		//if(gameData.length() < 2) {
		//	gameData = "LRL";
		//}
		// Decide on autonomous command group
		autoModeOptions = gameData[0];
		autoModeOptions += gameData[1];
		autoModeOptions += startingPosition;
		autoModeOptions += priorityGoal;
		autoModeOptions += crossField;

		// Left Switch, Scale does not matter, Left Starting, Switch Priority, cross field does not matter
		if (autoModeOptions == "LLLWN" ||
	        autoModeOptions == "LLLWY" ||
	        autoModeOptions == "LRLWN" ||
	        autoModeOptions == "LRLWY") {
			_autoCommandGroup = new Auto1();
		}
		// Right Switch, Scale does not matter, Right Starting, Switch Priority, cross field does not matter
		else if (autoModeOptions == "RRLWN" ||
                 autoModeOptions == "RRLWY" ||
                 autoModeOptions == "RLLWY" ||
                 autoModeOptions == "RLLWY") {
			_autoCommandGroup = new Auto1();
		}
		else {
			_autoCommandGroup = new Auto1();
		}


		if (_autoCommandGroup != nullptr) {
			_autoCommandGroup->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		if (_autoCommandGroup != nullptr) {
			_autoCommandGroup->Cancel();
			_autoCommandGroup = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {
}

};

START_ROBOT_CLASS(Robot)
