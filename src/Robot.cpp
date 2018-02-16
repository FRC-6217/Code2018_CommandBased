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
#include "CommandBase.h"
#include "ctre\Phoenix.h"

class Robot : public frc::TimedRobot {
public:

	void RobotInit() override {
		CommandBase::init();

		//m_chooser.AddDefault("Default Auto", new DriveDistance(20));
		m_chooser.AddObject("My Auto", new DriveWithJoystick());
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	}

	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() override {
		std::string gameData;
		std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");

		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		if(gameData.length() > 0) {
			if(gameData[0] == 'L') {
				//Put left auto code here
			}
			else {
				//Put right auto code here
			}
		}

//		if (autoSelected == "My Auto") {
//			m_autonomousCommand = &m_myAuto;
//		} else {
			m_autonomousCommand = &m_myAuto;
//		}

		m_autonomousCommand = m_chooser.GetSelected();

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {
//		frc::LiveWindow::GetInstance()->Run();
}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	//DriveDistance m_defaultAuto;
	DriveWithJoystick m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
};

START_ROBOT_CLASS(Robot)
