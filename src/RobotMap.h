#define TEST
#define SECONDARY_ROBOT
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
constexpr int SCREW_1_CHANNEL_A = 4;
constexpr int SCREW_1_CHANNEL_B = 5;
constexpr int SCREW_2_CHANNEL_A = 6;
constexpr int SCREW_2_CHANNEL_B = 7;
constexpr int LIFT_DIRECTION_UP = 1;
constexpr int LIFT_DIRECTION_DOWN = -1;
constexpr int LIFT_DIRECTION_STOP = 0;
constexpr float ACME_SCREW_SPEED = 0.5;

// Drive Train Motor Controller Ports
#ifdef SECONDARY_ROBOT
constexpr int VICTOR_SP_DRIVE_LEFT1		=	6; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_LEFT2		=	7; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_RIGHT1	=	8; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_RIGHT2	=	9; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_GRABBER_LEFT	=	4; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_GRABBER_RIGHT	=	5; /* DeviceID matches the PWM Port */
#endif
#ifndef SECONDARY_ROBOT
constexpr int VICTOR_SPX_DRIVE_LEFT1	=	40; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_LEFT2	=	41; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_RIGHT1	=	42; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_RIGHT2	=	43; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */

//Grabber Ports
constexpr int GRABBER_LEFT_SIDE_PORT = 45;
constexpr int GRABBER_RIGHT_SIDE_PORT = 46;

#endif

// Joystick Ports
constexpr int DRIVE_JOYSTICK_PORT	=	0;
constexpr int GAME_CONTROLLER_PORT  =	1;

// Joystick Items
constexpr int DRIVE_DISTANCE_BUTTON_NUMBER = 9;
constexpr int TURN_DEGREES_BUTTON = 10;
constexpr int RUN_GRABBER_BUTTON = 11;
constexpr int DRIVE_GOVERNOR_NUMBER = 3;
constexpr int LIFT_1_UP = 6; //Right Bumper Button
constexpr int LIFT_1_DOWN = 3; //Right Trigger Button
constexpr int LIFT_2_UP = 5; //Left Bumper Up
constexpr int LIFT_2_DOWN = 2; //Left Trigger Down
constexpr float TRIGGER_PERCENT_PRESS = .25;//trigger have a percent not a one
constexpr int GRABBER_IN_BUTTON = 1;//a button In
constexpr int GRABBER_OUT_BUTTON = 2;//b button Out
constexpr int GRABBER_STOP_BUTTON = 3;//x Button Stop
constexpr int GRABBER_LEFT_SIDE_AXIS = 1;
constexpr int GRABBER_RIGHT_SIDE_AXIS = 5;

// Pneumatics Items
constexpr int COMPRESSOR_PCM_ID = 0;
constexpr int PRESSURE_SENSOR_CHANNEL = 3;

//Grabber direction and speed
constexpr int GRABBER_IN = 1;
constexpr int GRABBER_OUT = -1;
constexpr int GRABBER_STOP = 0;
constexpr float GRABBER_SPEED = 1.0;

//Drive Sensor Channels
constexpr int LEFT_ENCODER_A_CHANNEL = 0;
constexpr int LEFT_ENCODER_B_CHANNEL = 1;
constexpr int RIGHT_ENCODER_A_CHANNEL = 2;
constexpr int RIGHT_ENCODER_B_CHANNEL = 3;

//Acceleration percent
constexpr double PERCENT_ACCEL = 1.01;

//Gyro Channel
constexpr double GYRO_PORT = 0;

//Distance for Encoder
constexpr double DRIVE_ENC_20_INCHES = 20;

//Grabber information
constexpr double SPIT_OUT_CUDE_TIME = 2;

//Auto distances
//Angle values
constexpr int L_TURN_RIGHT_DEGREES = 90;
constexpr int L_TURN_LEFT_DEGREES = -90;
constexpr int R_TURN_RIGHT_DEGREES = -90;
constexpr int R_TURN_LEFT_DEGREES = 90;
//LR_AutoLine
constexpr int LR_AUTOLINE_DISTANCE = 120;
//L_LeftSwitch and R_RightSwitch
constexpr int LR_FIRST_DISTANCE_SWITCH = 168;
constexpr int LR_SECOND_DISTANCE_SWITCH = 35;
//L_LeftScale and R_RightScale
constexpr int LR_SCALE_FIRST_DISTANCE = 310;
constexpr int LR_SCALE_SECOND_DISTANCE = 17;
//L_RightScale and R_LeftScale
constexpr int LR_OPPOSITE_SCALE_FIRST_DISTANCE = 223.5;
constexpr int LR_OPPOSITE_SCALE_SECOND_DISTANCE = 242;
constexpr int LR_OPPOSITE_SCALE_THIRD_DISTANCE = 86.5;
constexpr int LR_OPPOSITE_SCALE_FOURTH_DISTANCE = 17;
//L_RightSwitch and R_LeftSwitch
constexpr int LR_OPPOSITE_SWITCH_FIRST_DISTANCE = 223.5;
constexpr int LR_OPPOSITE_SWITCH_SECOND_DISTANCE = 161;
constexpr int LR_OPPOSITE_SWITCH_THIRD_DISTANCE = 47;
#endif // ROBOTMAP_H
