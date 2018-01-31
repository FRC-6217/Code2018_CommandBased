#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <WPILib.h>
#pragma once

// Drive Train Motor Controller Ports
constexpr int VICTOR_SPX_DRIVE_LEFT1	=	41; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_LEFT2	=	42; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_RIGHT1	=	43; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_RIGHT2	=	45; /* DeviceID matches the web-based config */

// Joystick Ports
constexpr int DRIVE_JOYSTICK_PORT	=	0;

// Joystick Button Numbers
constexpr int DRIVE_DISTANCE_BUTTON_NUMBER = 9;

#endif // ROBOTMAP_H
