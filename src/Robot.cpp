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
#include <CommandGroups\Auto1.h>
#include "CommandGroups\LR_AutoLine.h"
#include "CommandGroups\LeftSideAuto\L_LeftScale.h"
#include "CommandGroups\LeftSideAuto\L_LeftSwitch.h"
#include "CommandGroups\LeftSideAuto\L_RightScale.h"
#include "CommandGroups\LeftSideAuto\L_RightSwitch.h"
#include "CommandGroups\RightSideAuto\R_RightScale.h"
#include "CommandGroups\RightSideAuto\R_RightSwitch.h"
#include "CommandGroups\RightSideAuto\R_LeftScale.h"
#include "CommandGroups\RightSideAuto\R_LeftSwitch.h"
#include "CommandGroups\MiddleAuto\M_LeftAutoLine.h"
#include "CommandGroups\MiddleAuto\M_RightAutoLine.h"
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

	//Variables
	//Makes sure that if Scale and Switch don't work, the robot crosses base line
	int checker;
public:

	void RobotInit() override {
		CommandBase::init();

		// Build Autonomous Mode Choices on Smart Dashboard
		_chooserStartingPosition.AddObject("Left", "L");
		_chooserStartingPosition.AddObject("Middle", "M");
		_chooserStartingPosition.AddDefault("Right", "R");
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
			//gameData = "LRL";
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
			_autoCommandGroup = new L_LeftSwitch();
		}
		// Switch does not matter, Left Scale, Left Starting, Scale Priority, cross field does not matter
		else if (autoModeOptions == "LLLCN" ||
                 autoModeOptions == "LLLCY" ||
                 autoModeOptions == "RLLCN" ||
                 autoModeOptions == "RLLCY") {
			_autoCommandGroup = new L_LeftScale();
		}
		// Right Switch, Scale does not matter, Right Starting, Switch Priority, cross field does not matter
		else if (autoModeOptions == "RRRWN" ||
                 autoModeOptions == "RRRWY" ||
                 autoModeOptions == "RLRWN" ||
                 autoModeOptions == "RLRWY") {
			_autoCommandGroup = new R_RightSwitch();
		}
		// Switch does not matter, Right Scale, Right Starting, Scale Priority, cross field does not matter
		else if (autoModeOptions == "LRRCN" ||
                 autoModeOptions == "LRRCY" ||
                 autoModeOptions == "RRRCN" ||
                 autoModeOptions == "RRRCY") {
			_autoCommandGroup = new R_RightScale();
		}
		// Switch does not matter, Scale does not matter, Right or Left Starting, Auto Priority, cross field does not matter
		else if (autoModeOptions == "LLLAN" ||
				 autoModeOptions == "LLLAY" ||
				 autoModeOptions == "LRLAN" ||
				 autoModeOptions == "LRLAY" ||
				 autoModeOptions == "RLLAN" ||
				 autoModeOptions == "RLLAY" ||
				 autoModeOptions == "RRLAN" ||
				 autoModeOptions == "RRLAY" ||
				 autoModeOptions == "LLLAN" ||
				 autoModeOptions == "LLRAY" ||
				 autoModeOptions == "LRRAN" ||
				 autoModeOptions == "LRRAY" ||
				 autoModeOptions == "RLRAN" ||
				 autoModeOptions == "RLRAY" ||
				 autoModeOptions == "RRRAN" ||
				 autoModeOptions == "RRRAY") {
			_autoCommandGroup = new LR_AutoLine();
		}
		else if (autoModeOptions == "RRRWN" ||
                 autoModeOptions == "RRRWY" ||
                 autoModeOptions == "RLRWN" ||
                 autoModeOptions == "RLRWY") {
			_autoCommandGroup = new R_RightSwitch();
		}
		else {
			_autoCommandGroup = new LR_AutoLine();
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
