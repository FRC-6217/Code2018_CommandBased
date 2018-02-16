#ifndef OI_H
#define OI_H

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "WPILib.h"
#include <Buttons/JoystickButton.h>
#include <Joystick.h>

class OI {
private:
	Joystick * _driveStick;
	JoystickButton * _buttonDrive;
	JoystickButton * _buttonTurn;
	Joystick * _gameStick;
public:
	OI();
	Joystick* GetGameStick();
	Joystick* GetDriveStick();
};

#endif // OI_H
