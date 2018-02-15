/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include "RobotMap.h"
#include "Commands/DriveDistance.h"
#include "Commands/Turn90Degrees.h"

OI::OI() {
	_driveStick = new Joystick(DRIVE_JOYSTICK_PORT);
	_buttonDrive = new JoystickButton(_driveStick, DRIVE_DISTANCE_BUTTON_NUMBER);
	_gameStick = new Joystick(GAME_JOYSTICK_PORT);
	// Connect the buttons to commands
//	_buttonDrive->WhenPressed(new DriveDistance());
	_buttonDrive->WhenPressed(new Turn90Degrees());
}

Joystick* OI::GetDriveStick(){
	return _driveStick;
}
Joystick* OI::GetGameStick(){
	return _gameStick;
}
