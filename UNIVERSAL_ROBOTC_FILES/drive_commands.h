/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     drive_commands.h                                             */
/*    Author:     Jordan Kieltyka                                              */
/*    Created:    1 Feb 2015                                                   */
/*                                                                             */
/*    Revisions:                                                               */
/*                V1.00     1 Jan 2015 - Initial release                       */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    The author is supplying this software for use with the VEX cortex        */
/*    control system. this is free software; you can redistribute it           */
/*    and/or modify it under the terms of the GNU General Public License       */
/*    as published by the Free Software Foundation; either version 3 of        */
/*    the License, or (at your option) any later version.                      */
/*                                                                             */
/*    This software is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/*    GNU General Public License for more details.                             */
/*                                                                             */
/*    You should have received a copy of the GNU General Public License        */
/*    along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*                                                                             */
/*    The author can be contacted on the vex forums as Tick96                  */
/*    or electronic mail using jkieltyka_at_sbcglobal_dot_net                  */
/*    Programmer for team 6001A B1NARY BR0THERH00D, Green Bay, WI.             */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
#ifndef _DRIVE_COMMANDS_H
#define _DRIVE_COMMANDS_H

#pragma systemFile

#include "port_assignments.h"
#include "sensor_commands.h"

//the robot drive system will stop
void driveStop();

//the robot drive system is engaged
void driveGo(int left, int right, int straff);

//the robot drive system is engaged
void driveGo(int left, int right);

//the robot drive system is engaged
void driveGo(int velocity);

//the robot will drive for a desired of amount of time
void driveFor(int time, int left, int right, int straff);

//the robot will drive for a desired of amount of time
void driveFor(int time, int left, int right);

//the robot will drive for a desired of amount of time
void driveFor(int time, int velocity);

//the robot will travel a set amount of motor revolutions
void driveDistance(int left, int right, int straff);

//the robot will travel a set amount of motor revolutions
void driveDistance(int left, int right);

//the robot will travel a set amount of motor revolutions
void driveDistance(int distance);

//the robot x-drive straff is activated
void xStraffGo(int x, int y, int twist);

//the robot x-drive straff is activated
void xStraffGo(int x, int y);

//the robot x-drive straff is activated for a desired amount of time
void xStraffFor(int time, int x, int y, int twist);

//the robot x-drive straff is activated for a desired amount of time
void xStraffFor(int time, int x, int y);

//the robot x-drive straff is activated for a desired distance
void xStraffDistance(int x, int y, int twist);

//the robot x-drive straff is activated for a desired distance
void xStraffDistance(int x, int y);

//the robot will turn a desired amount of degrees
void turn(int degrees);

//switch drive motor ports
void flipDrive();

/***************************************************************************************
Function: driveStop()
Purpose: the robot drive system will stop
Entry Conditions: NONE
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
Special Note: NONE
***************************************************************************************/
void driveStop()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Drive Motors Halted");

	//stop right drive
	halt(rightDrive);

	//stop left drive
	halt(leftDrive);

	//stop straff drive
	halt(straffDrive);
}

/***************************************************************************************
Function: driveGo(int, int, int)
Purpose: the robot drive system is engaged
Entry Conditions:
left - velocity of the left drive system
right- velocity of the right drive system
straff - velocity of the straff drive system
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
Special Note: 3 overloaded functions
***************************************************************************************/
void driveGo(int left, int right, int straff)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Motors Engaged");
	writeDebugStreamLine("Left Velocity: %d", left);
	writeDebugStreamLine("Right Velocity: %d", right);
	writeDebugStreamLine("Straff Velocity: %d", straff);

	//engage right drive
	run(right, rightDrive);

	//engage left drive
	run(left, leftDrive);

	//engage straffing drive
	run(straff, straffDrive);
}

/***************************************************************************************
Function: driveGo(int, int)
Purpose: the robot drive system is engaged
Entry Conditions:
left - velocity of the left drive system
right- velocity of the right drive system
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
Special Note: 3 overloaded functions
***************************************************************************************/
void driveGo(int left, int right)
{
	//engage drives
	driveGo(left, right, 0);
}

/***************************************************************************************
Function: driveGo(int)
Purpose: the robot drive system is engaged
Entry Conditions: velocity - the velocity of the robot's drive system
Exit Conditions: NONE
Global: NONE
Special Note: 3 overloaded functions
***************************************************************************************/
void driveGo(int velocity)
{
	//engage left and right drive
	driveGo(velocity, velocity);
}

/***************************************************************************************
Function: driveFor(int, int, int, int)
Purpose: the robot drive system will go for a set amount of time
Entry Conditions:
time - the desired amount of time in milliseconds
right - the right drive motor system's velocity
left - the left drive motor system's velocity
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
Special Note: 2 overloaded functions
***************************************************************************************/
void driveFor(int time, int left, int right, int straff)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Motors Engaged For: %d", time);
	writeDebugStreamLine("ms");
	writeDebugStreamLine("Left Velocity: %d", left);
	writeDebugStreamLine("Right Velocity: %d", right);
	writeDebugStreamLine("Straff Velocity: %d", straff);

	//engage left, right and straff drive
	driveGo(left, right, straff);

	//wait for desired amount of time
	wait1Msec(time);

	//stop the drive
	driveStop();
}

/***************************************************************************************
Function: driveFor(int, int, int)
Purpose: the robot will drive for a desired of amount of time
Entry Conditions:
time - the desired amount of time in milliseconds
left - the robot's left motor system's velocity
right - the robot's right motor system's velocity
Exit Conditions: NONE
Global: NONE
Special Note: 3 overloaded functions
***************************************************************************************/
void driveFor(int time, int left, int right)
{
	// drive for a desired amount of time
	driveFor(time, left, right, 0);
}

/***************************************************************************************
Function: driveFor(int, int)
Purpose: the robot will drive for a desired of amount of time
Entry Conditions:
time - the desired amount of time in milliseconds
velocity - the robot's motor system's velocity
Exit Conditions: NONE
Global: NONE
Special Note: 3 overloaded functions
***************************************************************************************/
void driveFor(int time, int velocity)
{
	// drive for a desired amount of time
	driveFor(time, velocity, velocity);
}

/***************************************************************************************
Function: driveDistance(int, int)
Purpose: the robot will travel a set amount of motor revolutions
Entry Conditions:
right - the right drive motor system's target motor revolutions
left - the left drive motor system's target motor revolutions
straff - the straff drive motor system's target motor revolutions
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
straffDrive - the straff motor system
rightDriveSensor - the sensor that governs the right drive
leftDriveSensor - the sensor that governs the left drive
straffDriveSensor - the sensor that governs the straff drive
Special Note: 3 overloaded functions
***************************************************************************************/
void driveDistance(int left, int right, int straff)
{
	//Debug Stream
	writeDebugStreamLine(" ");
	writeDebugStream("Motors Engaged");
	writeDebugStream("Left: %d", left);
	writeDebugStreamLine("ticks");
	writeDebugStream("Right: %d", right);
	writeDebugStreamLine("ticks");
	writeDebugStream("Straff: %d", straff);
	writeDebugStreamLine("ticks");

	//set the current sensor values to zero
	zeroSensor(rightDriveSensor);
	zeroSensor(leftDriveSensor);
	zeroSensor(straffDriveSensor);

	//continue until both target values have been reached
	while(abs(getSensorValue(leftDriveSensor)) < abs(left)
		|| abs(getSensorValue(rightDriveSensor)) < abs(right)
	|| abs(getSensorValue(straffDriveSensor)) < abs(straff))
	{
		//engage motors
		driveGo(pid(driveMotorTrim, left, getSensorValue(leftDriveSensor)),
		pid(driveMotorTrim, right, -getSensorValue(rightDriveSensor)),
		pid(driveMotorTrim, straff, getSensorValue(straffDriveSensor)));
	}

	//stop the drive
	driveStop();
}

/***************************************************************************************
Function: driveDistance(int, int)
Purpose: the robot will travel a set amount of motor revolutions
Entry Conditions:
right - the right drive motor system's target motor revolutions
left - the left drive motor system's target motor revolutions
Exit Conditions: NONE
Global:
rightDrive - the right drive motor system
leftDrive - the left drive motor system
rightDriveSensor - the sensor that governs the right drive
leftDriveSensor - the sensor that governs the left drive
Special Note: 3 overloaded functions
***************************************************************************************/
void driveDistance(int left, int right)
{
	//travel a set amount of motor revolutions
	driveDistance(left, right, 0);
}

/***************************************************************************************
Function: driveDistance(int)
Purpose: the robot will travel a set amount of motor revolutions
Entry Conditions:
distance - the right drive motor system's target motor revolutions
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void driveDistance(int distance)
{
	//travel a set amount of motor revolutions
	driveDistance(distance, distance);
}

/***************************************************************************************
Function: xStraffGo(int, int, int)
Purpose: the robot x-drive straff is activated
Entry Conditions:
x - the horizontal velocity vector
y - the vertical velocity vector
twist - the rotating vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffGo(int x, int y, int twist)
{
	//Debug Stream
	writeDebugStreamLine(" ");
	writeDebugStream("Straffing Engaged");
	writeDebugStreamLine("X-Coordinate Velocity: %d", x);
	writeDebugStreamLine("Y-Coordinate Velocity: %d", y);
	writeDebugStreamLine("Twist Factor Velocity: %d", twist);

	//right drive
	for(int i = 0; i < rightDrive.motorAmt; i++)
	{
		//front right
		run((y - x - twist), rightDrive.motors[i]);

		//back right
		run((y + x - twist), rightDrive.motors[++i]);
	}

	//left drive
	for(int i = 0; i < leftDrive.motorAmt; i++)
	{
		//front left
		run((y + x + twist), leftDrive.motors[i]);

		//back left
		run((y - x + twist), leftDrive.motors[++i]);
	}
}

/***************************************************************************************
Function: xStraffGo(int, int)
Purpose: the robot x-drive straff is activated
Entry Conditions:
x - the horizontal velocity vector
y - the vertical velocity vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffGo(int x, int y)
{
	//engage straffing
	xStraffGo(x, y, 0);
}

/***************************************************************************************
Function: xStraffFor(int, int, int, int)
Purpose: the robot x-drive straff is activated for a desired amount of time
Entry Conditions:
time - the amount of time in milliseconds
x - the horizontal velocity vector
y - the vertical velocity vector
twist - the rotating vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffFor(int time, int x, int y, int twist)
{
	//Debug Stream
	writeDebugStreamLine(" ");
	writeDebugStream("Straffing Engaged For: %d", time);
	writeDebugStreamLine("ms");
	writeDebugStreamLine("X-Coordinate Velocity: %d", x);
	writeDebugStreamLine("Y-Coordinate Velocity: %d", y);
	writeDebugStreamLine("Twist Factor Velocity: %d", twist);

	//activate straffing
	xStraffGo(x, y, twist);

	//wait for desired amount of time
	wait1Msec(time);

	//stop the drive
	driveStop();
}

/***************************************************************************************
Function: xStraffFor(int, int, int)
Purpose: the robot x-drive straff is activated for a desired amount of time
Entry Conditions:
time - the amount of time in milliseconds
x - the horizontal velocity vector
y - the vertical velocity vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffFor(int time, int x, int y)
{
	//engage straffing for a desired amount of time
	xStraffFor(time, x, y, 0);
}

/***************************************************************************************
Function: xStraffDistance(int, int, int)
Purpose: the robot x-drive straff is activated for a desired distance
Entry Conditions:
x - the horizontal distance vector
y - the vertical distance vector
twist - the rotating distance vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffDistance(int x, int y, int twist)
{
	//Debug Stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Straffing Engaged");
	writeDebugStream("X-Coordinate Distance: %d", x);
	writeDebugStreamLine("ticks");
	writeDebugStream("Y-Coordinate Distance: %d", y);
	writeDebugStreamLine("ticks");
	writeDebugStream("Twist Factor Distance: %d", twist);
	writeDebugStreamLine("ticks");

	//set the current sensor values to zero
	zeroSensor(rightDriveSensor);
	zeroSensor(leftDriveSensor);

	//continue until both target values have been reached
	while(abs(getSensorValue(leftDriveSensor)) < abs(y+x+twist)
		|| abs(getSensorValue(rightDriveSensor)) < abs(y-x-twist))
	{
		//engage motors
		for(int i = 0; i < rightDrive.motorAmt; i++)
		{
			//front right
			run(pid(driveMotorTrim, y-x-twist, getSensorValue(leftDriveSensor)), rightDrive.motors[i]);

			//front left
			run(pid(driveMotorTrim, y+x+twist, -getSensorValue(rightDriveSensor)), leftDrive.motors[i]);

			//back right
			run(pid(driveMotorTrim, y+x-twist, -getSensorValue(rightDriveSensor)), rightDrive.motors[++i]);

			//back left
			run(pid(driveMotorTrim, y-x+twist, getSensorValue(leftDriveSensor)), leftDrive.motors[i]);
		}

		//stop the drive
		driveStop();
	}
}

/***************************************************************************************
Function: xStraffDistance(int, int)
Purpose: the robot x-drive straff is activated for a desired distance
Entry Conditions:
x - the horizontal distance vector
y - the vertical distance vector
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void xStraffDistance(int x, int y)
{
	//straff for a desired distance
	xStraffDistance(x, y, 0);
}

/***************************************************************************************
Function: turn(int)
Purpose: the robot will turn a desired amount of degrees
Entry Conditions:
turn - the amount of degrees the robot is to turn
Exit Conditions: NONE
Global: turnSensor - the sensor that govern the robot's rotation
Special Note: Uses gyro
***************************************************************************************/
void turn(int degrees)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Rotating: %d", degrees);
	writeDebugStreamLine("degrees");

	//convert into degrees
	degrees = degrees*10;

	//continue untill the target sensor value has been reached
	while(abs(getSensorValue(turnSensor)) < abs(degrees))
	{
		driveGo(pid(turnMotorTrim, degrees, getSensorValue(turnSensor)),
		(-pid(turnMotorTrim, degrees, getSensorValue(turnSensor))));
	}

	//stop the drive
	driveStop();
}

/***************************************************************************************
Function: flipDrive()
Purpose: switch drive motor ports
Entry Conditions: NONE
Exit Conditions: NONE
Global:
rightDrive - right drive motor system
leftDrive - left drive motor system
Special Note: Uses gyro
***************************************************************************************/
void flipDrive()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("DRIVE HAS BEEN FLIPPED");

	//create temporary drive place holders
	motorSystem tmpRight;
	motorSystem tmpLeft;

	//assign values to temporaty drive place holders
	tmpRight = rightDrive;
	tmpLeft = leftDrive;

	//flip the motors
	rightDrive = tmpLeft;
	leftDrive = tmpRight;

	//flip the straff motor
	for(int i = 0; i < straffDrive.motorAmt; i++)
		bMotorReflected[straffDrive.motors[i]] = !bMotorReflected[straffDrive.motors[i]];
}

#endif
