/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     universal_variables.h                                        */
/*    Author:     Jordan Kieltyka                                              */
/*    Created:    1 Jan 2015                                                   */
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
#ifndef _UNIVERSAL_VARIABLES_H
#define _UNIVERSAL_VARIABLES_H

#pragma systemFile

//Invalid variable value
const int NONE = -1;

//LCD buttons
const int leftButton = 1;
const int centerButton = 2;
const int rightButton = 4;

//controller types
const int MAIN = 0;
const int PARTNER = 1;

//alliance types
const int RED = 0;
const int BLUE = 1;

//current alliance
int alliance = NONE;

//starting tile locations
string position1 = "POS1";
string position2 = "POS2";

//current starting tile location
string startingTile = NONE;

//drive types
const int X_DRIVE = 0;
const int H_DRIVE = 1;
const int TANK_DRIVE = 2;

//the robot's drive type
int driveType = TANK_DRIVE;

//motor trimming
float xDriveMotorTrim = 1.2;
float liftMotorTrim = 0.7;
float driveMotorTrim = 0.7;
float turnMotorTrim = 0.7;

//Convert the port number to a string and print to debug stream
void sensorPortAsString(int port);

//Convert the port number to a string and print to debug stream
void portAsString(int port);

//Assign the drive type
void assignDriveType(int drive);

//Assign a value for the X-drive motor trim
void assignXDriveMotorTrim(float value);

//Assign a value for the lift motor trim
void assignLiftMotorTrim(float value);

//Assign a value for the turn motor trim
void assignTurnMotorTrim(float value);

//Assign a name to a position
void namePositions(string positionA, string positionB);

/***************************************************************************************
Function: sensorPortAsString(int)
Purpose: Convert the port number to a string and print to debug stream
Entry Conditions: port - the desired port to be converted to a string
Exit Conditions: NONE
Global:NONE
Special Note: Does not return a value
***************************************************************************************/
void sensorPortAsString(int port)
{
	//Return the string name of the port
	switch(port)
	{
		//analog 1
	case in1:
		writeDebugStream("in1");
		break;

		//analog 2
	case in2:
		writeDebugStream("in2");
		break;

		//analog 3
	case in3:
		writeDebugStream("in3");
		break;

		//analog 4
	case in4:
		writeDebugStream("in4");
		break;

		//analog 5
	case in5:
		writeDebugStream("in5");
		break;

		//analog 6
	case in6:
		writeDebugStream("in6");
		break;

		//analog 7
	case in7:
		writeDebugStream("in7");
		break;

		//analog 8
	case in8:
		writeDebugStream("in8");
		break;

		//digital 1
	case dgtl1:
		writeDebugStream("dgtl1");
		break;

		//digital 2
	case dgtl2:
		writeDebugStream("dgtl2");
		break;

		//digital 3
	case dgtl3:
		writeDebugStream("dgtl3");
		break;

		//digital 4
	case dgtl4:
		writeDebugStream("dgtl4");
		break;

		//digital 5
	case dgtl5:
		writeDebugStream("dgtl5");
		break;

		//digital 6
	case dgtl6:
		writeDebugStream("dgtl6");
		break;

		//digital 7
	case dgtl7:
		writeDebugStream("dgtl7");
		break;

		//digital 8
	case dgtl8:
		writeDebugStream("dgtl8");
		break;

		//digital 9
	case dgtl9:
		writeDebugStream("dgtl9");
		break;

		//digital 10
	case dgtl10:
		writeDebugStream("dgtl10");
		break;

		//digital 11
	case dgtl11:
		writeDebugStream("dgtl11");
		break;

		//digital 12
	case dgtl12:
		writeDebugStream("dgtl12");
		break;

		//digital I2C 1
	case I2C_1:
		writeDebugStream("I2C_1");
		break;

		//digital I2C 2
	case I2C_2:
		writeDebugStream("I2C_3");
		break;

		//digital I2C 4
	case I2C_4:
		writeDebugStream("I2C_4");
		break;

		//digital I2C 5
	case I2C_5:
		writeDebugStream("I2C_5");
		break;

		//digital I2C 6
	case I2C_6:
		writeDebugStream("I2C_6");
		break;

		//digital I2C 7
	case I2C_7:
		writeDebugStream("I2C_7");
		break;

		//digital I2C 8
	case I2C_8:
		writeDebugStream("I2C_8");
		break;
	}
}

/***************************************************************************************
Function: motorPortAsString(int)
Purpose: Convert the port number to a string and print to debug stream
Entry Conditions: port - the desired port to be converted to a string
Exit Conditions: NONE
Global:NONE
Special Note: Does not return a value
***************************************************************************************/
void motorPortAsString(int port)
{
	//Return the string name of the port
	switch(port)
	{
		//motor port 1
	case port1:
		writeDebugStream("port1");
		break;

		//motor port 2
	case port2:
		writeDebugStream("port2");
		break;

		//motor port 3
	case port3:
		writeDebugStream("port3");
		break;

		//motor port 4
	case port4:
		writeDebugStream("port4");
		break;

		//motor port 5
	case port5:
		writeDebugStream("port5");
		break;

		//motor port 6
	case port6:
		writeDebugStream("port6");
		break;

		//motor port 7
	case port7:
		writeDebugStream("port7");
		break;

		//motor port 8
	case port8:
		writeDebugStream("port8");
		break;

		//motor port 9
	case port9:
		writeDebugStream("port9");
		break;

		//motor port 10
	case port10:
		writeDebugStream("port10");
		break;
	}
}

/***************************************************************************************
Function: assignDriveType(int)
Purpose: assign the robot a drive type
Entry Conditions: drive - the desired drive type
Exit Conditions: NONE
Global:NONE
Special Note: Drive Options: X_DRIVE, TANK_DRIVE, H_DRIVE
***************************************************************************************/
void assignDriveType(int drive)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Drive Type");
	writeDebugStream("Drive Type: ");

	//write what drive it is
	switch(drive)
	{
		//x-drive
	case X_DRIVE:
		writeDebugStreamLine("X-Drive");
		break;

		//h-drive
	case H_DRIVE:
		writeDebugStreamLine("H-Drive");
		break;

		//tank drive
	case TANK_DRIVE:
		writeDebugStreamLine("Tank Drive");
		break;
	}

	//Assign desired drive type
	driveType = drive;
}

/***************************************************************************************
Function: assignXDriveMotorTrim(float)
Purpose: assign the x-drive motor trim value
Entry Conditions: value - the desired motor trim value
Exit Conditions: NONE
Global:NONE
Special Note: Use only for an X-Drive
***************************************************************************************/
void assignXDriveMotorTrim(float value)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning X-Drive Motor Trim");
	writeDebugStreamLine("Value: %f", value);

	//assign value
	xDriveMotorTrim = value;
}

/***************************************************************************************
Function: assignLiftMotorTrim(float)
Purpose: assign the lift motor trim value
Entry Conditions: value - the desired motor trim value
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
void assignLiftMotorTrim(float value)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Lift Motor Trim");
	writeDebugStreamLine("Value: %f", value);

	//assign value
	liftMotorTrim = value;
}

/***************************************************************************************
Function: assignDriveMotorTrim(float)
Purpose: assign the drive motor trim value
Entry Conditions: value - the desired motor trim value
Exit Conditions: NONE
Global:NONE
Special Note: Autonomous use only
***************************************************************************************/
void assignDriveMotorTrim(float value)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Drive Motor Trim");
	writeDebugStreamLine("Value: %f", value);

	//assign value
	driveMotorTrim = value;
}

/***************************************************************************************
Function: assignTurnMotorTrim(float)
Purpose: assign the turn motor trim value
Entry Conditions: value - the desired motor trim value
Exit Conditions: NONE
Global:NONE
Special Note: Autonomous use only
***************************************************************************************/
void assignTurnMotorTrim(float value)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Turn Motor Trim");
	writeDebugStreamLine("Value: %f", value);

	//assign value
	turnMotorTrim = value;
}

/***************************************************************************************
Function: namePositions(unsigned string, unsigned string)
Purpose: assign the names for position1 and position2
Entry Conditions:
positionA - the new name for position1
positionB - the new name for position2
Exit Conditions: NONE
Global:NONE
Special Note: Autonomous use only
***************************************************************************************/
void namePositions(string positionA, string positionB)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Renaming Positions");
	writeDebugStream(position1);
	writeDebugStream(" is now ");
	writeDebugStreamLine(positionA);
	writeDebugStream(position2);
	writeDebugStream(" is now ");
	writeDebugStreamLine(positionB);

	//name position1
	position1 = positionA;

	//name position2
	position2 = positionB;
}

#endif
