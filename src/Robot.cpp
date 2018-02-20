/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Assigns words to numbers for easier use in Autonomous Priority Arrays
#define SWITCH 0
#define SCALE 1
#define OPPOSITE_SWITCH 2
#define OPPOSITE_SCALE 3
#define AUTO_LINE 4

#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <TimedRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/DriveDistance.h"
#include "Commands/DriveWithJoystick.h"
#include <CommandGroups/Auto1.h>
#include "CommandGroups/LR_AutoLine.h"
#include "CommandGroups/LR_SideSwitch.h"

#include "CommandGroups\LeftSideAuto\L_LeftScale.h"
#include "CommandGroups\LeftSideAuto\L_LeftSwitch.h"
#include "CommandGroups\LeftSideAuto\L_RightScale.h"
#include "CommandGroups\LeftSideAuto\L_RightSwitch.h"
#include "CommandGroups\RightSideAuto\R_RightScale.h"
#include "CommandGroups\RightSideAuto\R_RightSwitch.h"
#include "CommandGroups\RightSideAuto\R_LeftScale.h"
#include "CommandGroups\RightSideAuto\R_LeftSwitch.h"
#include "CommandGroups\MiddleAuto\M_Switch.h"
#include "CommandGroups\MiddleAuto\M_LeftAutoLine.h"
#include "CommandGroups\MiddleAuto\M_RightAutoLine.h"
#include "CommandGroups\LR_SideScale.h"
#include "CommandGroups\LR_SideSwitch.h"
#include "CommandGroups\LR_AutoLine.h"
#include "CommandBase.h"
#include "ctre\Phoenix.h"

class Robot : public frc::TimedRobot {
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::CommandGroup* _autoCommandGroup = nullptr;

	//Choose Starting Position variable
	frc::SendableChooser<std::string> _chooserStartingPosition;

	//Choose Priority Variables
	frc::SendableChooser<int> _chooserPrioritySwitch;
	frc::SendableChooser<int> _chooserPriorityScale;
	frc::SendableChooser<int> _chooserPriorityOppositeSwitch;
	frc::SendableChooser<int> _chooserPriorityOppositeScale;
	frc::SendableChooser<int> _chooserPriorityAutoLine;

	//Choose if want to Cross to opposite side of field variable
	frc::SendableChooser<std::string> _chooserCrossField;

	//Variables

public:

	void RobotInit() override {
		CommandBase::init();

		// Build Autonomous Mode Choices on Smart Dashboard

		//Choose Starting Position
		_chooserStartingPosition.AddObject("Left", "L");
		_chooserStartingPosition.AddObject("Middle", "M");
		_chooserStartingPosition.AddDefault("Right", "R");
		frc::SmartDashboard::PutData("Starting Position", &_chooserStartingPosition);


		//Choose Priority Switch
		_chooserPrioritySwitch.AddDefault("1", 1);
		_chooserPrioritySwitch.AddObject("2", 2);
		_chooserPrioritySwitch.AddObject("3", 3);
		_chooserPrioritySwitch.AddObject("4", 4);
		_chooserPrioritySwitch.AddObject("5", 5);
		frc::SmartDashboard::PutData("Switch Priority", &_chooserPrioritySwitch);

		//Choose Priority Scale
		_chooserPriorityScale.AddObject("1", 1);
		_chooserPriorityScale.AddDefault("2", 2);
		_chooserPriorityScale.AddObject("3", 3);
		_chooserPriorityScale.AddObject("4", 4);
		_chooserPriorityScale.AddObject("5", 5);
		frc::SmartDashboard::PutData("Scale Priority", &_chooserPriorityScale);

		//Choose Priority Opposite Switch
		_chooserPriorityOppositeSwitch.AddObject("1", 1);
		_chooserPriorityOppositeSwitch.AddObject("2", 2);
		_chooserPriorityOppositeSwitch.AddDefault("3", 3);
		_chooserPriorityOppositeSwitch.AddObject("4", 4);
		_chooserPriorityOppositeSwitch.AddObject("5", 5);
		frc::SmartDashboard::PutData("Opposite Switch Priority", &_chooserPriorityOppositeSwitch);

		//Choose Priority Opposite Scale
		_chooserPriorityOppositeScale.AddObject("1", 1);
		_chooserPriorityOppositeScale.AddObject("2", 2);
		_chooserPriorityOppositeScale.AddObject("3", 3);
		_chooserPriorityOppositeScale.AddDefault("4", 4);
		_chooserPriorityOppositeScale.AddObject("5", 5);
		frc::SmartDashboard::PutData("Opposite Scale Priority", &_chooserPriorityOppositeScale);

		//Choose Priority AutoLine
		_chooserPriorityAutoLine.AddObject("1", 1);
		_chooserPriorityAutoLine.AddObject("2", 2);
		_chooserPriorityAutoLine.AddObject("3", 3);
		_chooserPriorityAutoLine.AddObject("4", 4);
		_chooserPriorityAutoLine.AddDefault("5", 5);
		frc::SmartDashboard::PutData("AutoLine Priority", &_chooserPriorityAutoLine);

		//Put Priority Order


		//Choose if want to Cross field for scoring
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
		//variables for use in auto Chooser
		std::string gameData;
		std::string switchPosition;
		std::string scalePosition;
		std::string startingPosition;
		int priorityGoal[5];
		std::string crossField;

		//Set Starting Position
		startingPosition = _chooserStartingPosition.GetSelected();

		//Set Priority Order
		priorityGoal[SWITCH] = _chooserPrioritySwitch.GetSelected();
		priorityGoal[SCALE] = _chooserPriorityScale.GetSelected();
		priorityGoal[OPPOSITE_SWITCH] = _chooserPriorityOppositeSwitch.GetSelected();
		priorityGoal[OPPOSITE_SCALE] = _chooserPriorityOppositeScale.GetSelected();
		priorityGoal[AUTO_LINE] = _chooserPriorityAutoLine.GetSelected();

		//Set if want to Cross field for scoring
		crossField = _chooserCrossField.GetSelected();


		// Game data - for 2018 three characters indicating position of switch and scale (e.g. LRL)
		//gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		// Default game data
		gameData = "LRL";
		switchPosition = gameData[0];
		scalePosition = gameData[1];

		//Choose which Autonomous CommandGroup to run based on Inputs from SmartDashboard and Field Management System
		bool found = false;
		for (int currentPri = 0; currentPri <= 4 && found != true; currentPri++) {
			//Runs if Switch is current priority and if the switch is on the same side as the starting position
			if (currentPri == priorityGoal[SWITCH] && switchPosition == startingPosition) {
				_autoCommandGroup = new LR_SideSwitch(switchPosition);
				found = true;
			}
			//Runs if Scale is current priority and if the scale is on the same side as the starting position
			else if (currentPri == priorityGoal[SCALE] && scalePosition == startingPosition) {
				_autoCommandGroup = new LR_SideScale(scalePosition);
				found = true;
			}
			//Runs if Opposite side Switch is current priority and if that switch is not on the same side as the starting position
			else if (currentPri == priorityGoal[OPPOSITE_SWITCH] && switchPosition != startingPosition && crossField == "Y") {
				if (startingPosition == "L") {
					_autoCommandGroup = new L_RightSwitch();
				}
				else {
					_autoCommandGroup = new R_LeftSwitch();
				}
				found = true;
			}
			//Runs if Opposite side Scale is current priority and if that scale is not on the same side as the starting position
			else if (currentPri == priorityGoal[OPPOSITE_SCALE] && scalePosition != startingPosition && crossField == "Y") {
				if (startingPosition == "L") {
					_autoCommandGroup = new L_RightScale();
				}
				else {
					_autoCommandGroup = new R_LeftScale();
				}
				found = true;
			}
			//Runs if Auto Line is current priority and the starting position is not the middle
			else if (currentPri == priorityGoal[AUTO_LINE] && startingPosition != "M") {
				_autoCommandGroup = new LR_AutoLine();
				found = true;
			}
			//Runs if Switch is current priority and the starting position is the middle
			else if (currentPri == priorityGoal[SWITCH] && startingPosition == "M") {
				_autoCommandGroup = new M_Switch(switchPosition);
				found = true;
			}
			//Runs if Auto line is current priority and the starting position is the middle
			else if (currentPri == priorityGoal[AUTO_LINE] && startingPosition == "M") {
				if (switchPosition == "L") {
					_autoCommandGroup = new M_RightAutoLine(); // Go Right to avoid other robots
				}
				else {
					_autoCommandGroup = new M_LeftAutoLine(); // Go Left to avoid other robots
				}
				found = true;
			}
		}

		// Default Auto Command
		if (!found) {
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
