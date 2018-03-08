/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Assigns words to numbers for easier use in Autonomous Priority Array
#define SWITCH 0
#define SCALE 1
#define OPPOSITE_SWITCH 2
#define OPPOSITE_SCALE 3
#define AUTO_LINE 4

#include <memory>

#include <TimedRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <CommandGroups\Auto1.h>
#include "CommandGroups\LR_AutoLine.h"
#include "CommandGroups\LR_SideScale.h"
#include "CommandGroups\LR_SideSwitch.h"
#include "CommandGroups\LeftSideAuto\L_LeftScale.h"
#include "CommandGroups\LeftSideAuto\L_LeftSwitch.h"
#include "CommandGroups\LeftSideAuto\L_RightScale.h"
#include "CommandGroups\LeftSideAuto\L_RightSwitch.h"
#include "CommandGroups\MiddleAuto\M_LeftAutoLine.h"
#include "CommandGroups\MiddleAuto\M_RightAutoLine.h"
#include "CommandGroups\MiddleAuto\M_Switch.h"
#include "CommandGroups\RightSideAuto\R_LeftScale.h"
#include "CommandGroups\RightSideAuto\R_LeftSwitch.h"
#include "CommandGroups\RightSideAuto\R_RightScale.h"
#include "CommandGroups\RightSideAuto\R_RightSwitch.h"
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

	//Variable

public:

	void RobotInit() override {
		CommandBase::init();

		// Build Autonomous Mode Choices on Smart Dashboard

		//Choose Starting Position
		_chooserStartingPosition.AddObject("Left Outside", "LO");
		_chooserStartingPosition.AddObject("Left Inside", "LI");
		_chooserStartingPosition.AddObject("Middle", "M");
		_chooserStartingPosition.AddDefault("Right Outside", "RO");
		_chooserStartingPosition.AddObject("Right Inside", "RI");
		frc::SmartDashboard::PutData("Starting Position", &_chooserStartingPosition);

		//Choose Priority AutoLine
		_chooserPriorityAutoLine.AddDefault("1", 1);
		_chooserPriorityAutoLine.AddObject("2", 2);
		_chooserPriorityAutoLine.AddObject("3", 3);
		_chooserPriorityAutoLine.AddObject("4", 4);
		_chooserPriorityAutoLine.AddObject("5", 5);
		frc::SmartDashboard::PutData("AutoLine Priority", &_chooserPriorityAutoLine);

		//Choose Priority Switch
		_chooserPrioritySwitch.AddObject("1", 1);
		_chooserPrioritySwitch.AddDefault("2", 2);
		_chooserPrioritySwitch.AddObject("3", 3);
		_chooserPrioritySwitch.AddObject("4", 4);
		_chooserPrioritySwitch.AddObject("5", 5);
		frc::SmartDashboard::PutData("Switch Priority", &_chooserPrioritySwitch);

		//Choose Priority Scale
		_chooserPriorityScale.AddObject("1", 1);
		_chooserPriorityScale.AddObject("2", 2);
		_chooserPriorityScale.AddDefault("3", 3);
		_chooserPriorityScale.AddObject("4", 4);
		_chooserPriorityScale.AddObject("5", 5);
		frc::SmartDashboard::PutData("Scale Priority", &_chooserPriorityScale);

		//Choose Priority Opposite Switch
		_chooserPriorityOppositeSwitch.AddObject("1", 1);
		_chooserPriorityOppositeSwitch.AddObject("2", 2);
		_chooserPriorityOppositeSwitch.AddObject("3", 3);
		_chooserPriorityOppositeSwitch.AddDefault("4", 4);
		_chooserPriorityOppositeSwitch.AddObject("5", 5);
		frc::SmartDashboard::PutData("Opposite Switch Priority", &_chooserPriorityOppositeSwitch);

		//Choose Priority Opposite Scale
		_chooserPriorityOppositeScale.AddObject("1", 1);
		_chooserPriorityOppositeScale.AddObject("2", 2);
		_chooserPriorityOppositeScale.AddObject("3", 3);
		_chooserPriorityOppositeScale.AddObject("4", 4);
		_chooserPriorityOppositeScale.AddDefault("5", 5);
		frc::SmartDashboard::PutData("Opposite Scale Priority", &_chooserPriorityOppositeScale);

		//Put Priority Order


		//Choose if want to Cross field for scoring
		_chooserCrossField.AddDefault("No", "N");
		_chooserCrossField.AddObject("Yes", "Y");
		frc::SmartDashboard::PutData("Cross field for Goal", &_chooserCrossField);

		// Add Command Based Scheduler Status to dashboard
		frc::SmartDashboard::PutData(frc::Scheduler::GetInstance());
		// Add test commands on Smart Dashboard
		frc::SmartDashboard::PutData("Test Auto 1", new Auto1());
		frc::SmartDashboard::PutData("Test Middle Left Auto Line", new M_LeftAutoLine());
		frc::SmartDashboard::PutData("Test Middle Right Auto Line", new M_RightAutoLine());
		frc::SmartDashboard::PutData("Test Right side Right Switch", new R_RightSwitch());
		frc::SmartDashboard::PutData("Test Left side Left Switch", new L_LeftSwitch());
		frc::SmartDashboard::PutData("Drive 20 inches", new DriveDistance(20));
		frc::SmartDashboard::PutData("Turn 90 degrees", new TurnDegrees(90));

		//test Pathfinder from SmartDashboard
		//frc::SmartDashboard::PutData("Test Pathfinder", new Follow3PointTrajectory(2, 2, 315, -2, 4, 45, 2, 6, 0));
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
		std::string crossField;
		std::string chosenAuto;
		std::string leftOrRightStart;
		std::string insideOrOutside;
		std::string outside;
		std::string left;
		//Set Starting Position
		startingPosition = _chooserStartingPosition.GetSelected();
		leftOrRightStart = startingPosition[0];
		insideOrOutside = startingPosition[1];
		outside = 'O';
		left = "L";

		//Set Priority Order
		int priorityGoal[5];
		priorityGoal[SWITCH] = _chooserPrioritySwitch.GetSelected();
		priorityGoal[SCALE] = _chooserPriorityScale.GetSelected();
		priorityGoal[OPPOSITE_SWITCH] = _chooserPriorityOppositeSwitch.GetSelected();
		priorityGoal[OPPOSITE_SCALE] = _chooserPriorityOppositeScale.GetSelected();
		priorityGoal[AUTO_LINE] = _chooserPriorityAutoLine.GetSelected();

		//Set if want to Cross field for scoring
		crossField = _chooserCrossField.GetSelected();


#ifndef TEST
		// Game data - for 2018 three characters indicating position of switch and scale (e.g. LRL)
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
#endif
#ifdef TEST
		// Default game data
		gameData = "LRL";
#endif
		frc::SmartDashboard::PutString("Game Data", gameData);
		switchPosition = gameData[0];
		scalePosition = gameData[1];

		bool found = false;
		//Choose which Autonomous CommandGroup to run based on Inputs from SmartDashboard and Field Management System
		for (int currentPri = 0; currentPri <= 4 && found != true; currentPri++) {
			//Runs if Switch is current priority and if the switch is on the same side as the starting position
			if (currentPri == priorityGoal[SWITCH] && switchPosition == leftOrRightStart) {
				if(insideOrOutside == outside){
					_autoCommandGroup = new LR_SideSwitch(switchPosition);
					chosenAuto = "LR_SideSwitch";
				}
				else{
					if (switchPosition == left){
						_autoCommandGroup = new L_LeftSwitch();
						chosenAuto = "L_LeftSwitch";
					}
					else{
						_autoCommandGroup = new L_LeftSwitch();
						chosenAuto = "R_RightSwitch";
					}

				}
				found = true;
			}
			//Runs if Scale is current priority and if the scale is on the same side as the starting position
			else if (currentPri == priorityGoal[SCALE] && scalePosition == startingPosition) {
				_autoCommandGroup = new LR_SideScale(scalePosition);
				chosenAuto = "LR_SideScale";
				found = true;
			}
			//Runs if Opposite side Switch is current priority and if that switch is not on the same side as the starting position
			else if (currentPri == priorityGoal[OPPOSITE_SWITCH] && switchPosition != startingPosition && crossField == "Y") {
				if (startingPosition == "L") {
					_autoCommandGroup = new L_RightSwitch();
					chosenAuto = "L_RightSwitch";
				}
				else {
					_autoCommandGroup = new R_LeftSwitch();
					chosenAuto = "R_LeftSwitch";
				}
				found = true;
			}
			//Runs if Opposite side Scale is current priority and if that scale is not on the same side as the starting position
			else if (currentPri == priorityGoal[OPPOSITE_SCALE] && scalePosition != startingPosition && crossField == "Y") {
				if (startingPosition == "L") {
					_autoCommandGroup = new L_RightScale();
					chosenAuto = "L_RightScale";
				}
				else {
					_autoCommandGroup = new R_LeftScale();
					chosenAuto = "R_LeftScale";
				}
				found = true;
			}
			//Runs if Auto Line is current priority and the starting position is not the middle
			else if (currentPri == priorityGoal[AUTO_LINE] && startingPosition != "M") {
				_autoCommandGroup = new LR_AutoLine();
				chosenAuto = "LR_AutoLine";
				found = true;
			}
			//Runs if Switch is current priority and the starting position is the middle
			else if (currentPri == priorityGoal[SWITCH] && startingPosition == "M") {
				_autoCommandGroup = new M_Switch(switchPosition);
				chosenAuto = "M_Switch";
				found = true;
			}
			//Runs if Auto line is current priority and the starting position is the middle
			else if (currentPri == priorityGoal[AUTO_LINE] && startingPosition == "M") {
				if (switchPosition == "L") {
					_autoCommandGroup = new M_RightAutoLine(); // Go Right to avoid other robots
					chosenAuto = "M_RightAutoLine";
				}
				else {
					_autoCommandGroup = new M_LeftAutoLine(); // Go Left to avoid other robots
					chosenAuto = "M_LeftAutoLine";
				}
				found = true;
			}
		}

		// Default Auto Command
		if (!found) {
			_autoCommandGroup = new LR_AutoLine();
			chosenAuto = "LR_AutoLine";
		}

		if (_autoCommandGroup != nullptr) {
			_autoCommandGroup->Start();
		}
		frc::SmartDashboard::PutString("Auto Mode", chosenAuto);
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

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
	}

};

START_ROBOT_CLASS(Robot)
