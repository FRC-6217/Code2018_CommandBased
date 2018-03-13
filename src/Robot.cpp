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
#include <iostream>
//#include <cscore_oo.h>
#include <TimedRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CommandGroups\Auto1.h"
#include "CommandGroups\LR_AutoLine.h"
#include "CommandGroups\LR_SideScale.h"
#include "CommandGroups\LR_SideSwitch.h"
#include "CommandGroups\LeftSideAuto\L_RightScale.h"
#include "CommandGroups\LeftSideAuto\L_RightSwitch.h"
#include "CommandGroups\MiddleAuto\M_LeftAutoLine.h"
#include "CommandGroups\MiddleAuto\M_RightAutoLine.h"
#include "CommandGroups\MiddleAuto\M_Switch.h"
#include "CommandGroups\RightSideAuto\R_LeftScale.h"
#include "CommandGroups\RightSideAuto\R_LeftSwitch.h"
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
	frc::SendableChooser<int> _chooserCrossField;
	frc::SendableChooser<int> _chooserPriorityAutoLine;
	frc::SendableChooser<int> _chooserPriorityScale;
	frc::SendableChooser<int> _chooserPriorityOppositeSwitch;
	frc::SendableChooser<int> _chooserPriorityOppositeScale;

	//variables

	// camera define
//	cs::UsbCamera camera;
//	cs::CvSink cvSink;
//	cs::CvSource outputStreamStd;
//	cv::Mat source;

public:

	void RobotInit() override {

		CommandBase::init();

		// Build Autonomous Mode Choices on Smart Dashboard

		//Choose Starting Position
		_chooserStartingPosition.AddObject("Left", "L");
		_chooserStartingPosition.AddDefault("Middle", "M");
		_chooserStartingPosition.AddObject("Right", "R");
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

		// Add Command Based Scheduler Status to dashboard
		frc::SmartDashboard::PutData(frc::Scheduler::GetInstance());
		// Add test commands on Smart Dashboard
		frc::SmartDashboard::PutData("Test Auto 1", new Auto1());
		frc::SmartDashboard::PutData("Test Middle Left Auto Line", new M_LeftAutoLine());
		frc::SmartDashboard::PutData("Test Middle Right Auto Line", new M_RightAutoLine());
		frc::SmartDashboard::PutData("Drive 20 inches", new DriveDistance(20));
		frc::SmartDashboard::PutData("Turn 90 degrees", new TurnDegrees(90));
		//frc::SmartDashboard::PutData("Lift1 20 inches", new AutoLift1(20, -1));
		frc::SmartDashboard::PutData("Lift2 15 inches", new AutoLift2(15, -1));

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
		std::string outside;
		std::string left;
		//Set Starting Position
		startingPosition = _chooserStartingPosition.GetSelected();

		//Set Priority Order
		int priorityGoal[5];
		priorityGoal[SWITCH] = _chooserPrioritySwitch.GetSelected();
		priorityGoal[SCALE] = _chooserPriorityScale.GetSelected();
		priorityGoal[OPPOSITE_SWITCH] = _chooserPriorityOppositeSwitch.GetSelected();
		priorityGoal[OPPOSITE_SCALE] = _chooserPriorityOppositeScale.GetSelected();
		priorityGoal[AUTO_LINE] = _chooserPriorityAutoLine.GetSelected();

		// Game data - for 2018 three characters indicating position of switch and scale (e.g. LRL)
		//SetTimeout(2);
//		int i = 0;

		WaitCommand(.2);
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

//		while(gameData.empty() || (i < 50)) {
//			gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
//			WaitCommand(.02);
//			i++;
//		}
//		if (gameData.empty()){
//			gameData = "MMM";//THis will automatically go to autoLine
//		}

		frc::SmartDashboard::PutString("Game Data", gameData);
		switchPosition = gameData[0];
		scalePosition = gameData[1];

		bool found = false;
		//Choose which Autonomous CommandGroup to run based on Inputs from SmartDashboard and Field Management System
		for (int currentPri = 0; currentPri <= 4 && found != true; currentPri++) {
			//Runs if Switch is current priority and if the switch is on the same side as the starting position
			if (currentPri == priorityGoal[SWITCH] && switchPosition == startingPosition) {
				_autoCommandGroup = new LR_SideSwitch(switchPosition);
				chosenAuto = "LR_SideSwitch";
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

//		//getting the camera values cvSink.GrabFrame(source);
//		cvSink.GrabFrame(source);
//		//Send to driver station
//		outputStreamStd.PutFrame(source);

		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		if (_autoCommandGroup != nullptr) {
			_autoCommandGroup->Cancel();
			_autoCommandGroup = nullptr;
		}
	}

	void TeleopPeriodic() override {

//		//getting the camera values cvSink.GrabFrame(source);
//		cvSink.GrabFrame(source);
//		//Send to driver station
//		outputStreamStd.PutFrame(source);

		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
	}

};

START_ROBOT_CLASS(Robot)
