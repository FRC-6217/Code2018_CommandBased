/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/TurnDegrees.h>
#include "OI.h"

#include <WPILib.h>
#include "RobotMap.h"
#include "Commands/DriveDistance.h"
#include "Commands/spitOutCube.h"

OI::OI() {
	_driveStick = new Joystick(DRIVE_JOYSTICK_PORT);
	_buttonGrabOut = new JoystickButton(_driveStick, 11);
	_buttonDrive = new JoystickButton(_driveStick, DRIVE_DISTANCE_BUTTON_NUMBER);
	_buttonTurn = new JoystickButton(_driveStick, TURN_DEGREES_BUTTON);
	_gameStick = new Joystick(GAME_JOYSTICK_PORT);
	// Connect the buttons to commands
	_buttonDrive->WhenPressed(new DriveDistance(10));
	_buttonTurn->WhenPressed(new TurnDegrees(45));
	_buttonGrabOut->WhenPressed(new spitOutCube);
}

Joystick* OI::GetDriveStick(){
	return _driveStick;
}
Joystick* OI::GetGameStick(){
	return _gameStick;
}
