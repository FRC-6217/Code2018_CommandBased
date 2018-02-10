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

//Lift motor controller ports
constexpr int SPARK_ACMESCREW_1 = 0;
constexpr int SPARK_ACMESCREW_2 = 1;
constexpr int LIFT_DIRECTION_UP = 1;
constexpr int LIFT_DIRECTION_DOWN = -1;
constexpr int LIFT_DIRECTION_STOP = 0;
constexpr float ACME_SCREW_SPEED = 0.5;

// Drive Train Motor Controller Ports
constexpr int VICTOR_SPX_DRIVE_LEFT1	=	40; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_LEFT2	=	41; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_RIGHT1	=	42; /* DeviceID matches the web-based config */
constexpr int VICTOR_SPX_DRIVE_RIGHT2	=	43; /* DeviceID matches the web-based config */

// Joystick Ports
constexpr int DRIVE_JOYSTICK_PORT	=	0;
constexpr int GAME_JOYSTICK_PORT  =	1;

// Joystick Items
constexpr int DRIVE_DISTANCE_BUTTON_NUMBER = 9;
constexpr int DRIVE_GOVERNOR_NUMBER = 3;
constexpr int LIFT_1_UP = 6; //Right Bumper Button
constexpr int LIFT_1_DOWN = 3; //Right Trigger Button
constexpr int LIFT_2_UP = 5; //Left Bumper Up
constexpr int LIFT_2_DOWN = 2; //Left Trigger Down
constexpr float TRIGGER_PERCENT_PRESS = .25;//trigger have a percent not a one
constexpr int GRABBER_IN_BUTTON = 1;//a button
constexpr int GRABBER_OUT_BUTTON = 2;//b button

// Pneumatics Items
constexpr int COMPRESSOR_PCM_ID = 0;
constexpr int PRESSURE_SENSOR_CHANNEL = 3;

//Grabber Ports
constexpr int GRABBER_LEFT_SIDE_PORT = 45;
constexpr int GRABBER_RIGHT_SIDE_PORT = 46;

//Grabber direction and speed
constexpr int GRABBER_IN = 1;
constexpr int GRABBER_OUT = -1;
constexpr int GRABBER_STOP = 0;
constexpr float GRABBER_SPEED = 1.0;

#endif // ROBOTMAP_H
