/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     straff_drive_motor_assignments.h                             */
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
#ifndef _STRAFF_DRIVE_MOTOR_ASSIGNMENTS_H
#define _STRAFF_DRIVE_MOTOR_ASSIGNMENTS_H

#pragma systemFile

#include "port_object.h"

//Create Right Drive Motor Object
motorSystem straffDrive;

//Prototypes for assigning motors for the right drive train
void assignStraffDriveMotors();
void assignStraffDriveMotors(int one);
void assignStraffDriveMotors(int one, int two);
void assignStraffDriveMotors(int one, int two, int three);
void assignStraffDriveMotors(int one, int two, int three, int four);
void assignStraffDriveMotors(int one, int two, int three, int four, int five);
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six);
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven);
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight);
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine);
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten);

/***************************************************************************************
Function: assignStraffDriveMotors(int...)
Purpose: assign motors for the right drive train
Entry Conditions: one->ten - desired motor system ports
Exit Conditions: NONE
Global: straffDrive - the motor system being assigned
Special Note: 11 overloaded functions
***************************************************************************************/
//zero motors
void assignStraffDriveMotors()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");
	writeDebugStreamLine("Ports: NONE");

	//no motors
	resetMotorSystem(straffDrive);
}

//one motor
void assignStraffDriveMotors(int one)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor port
	assignMotorSystem(straffDrive, one);
}

//two motors
void assignStraffDriveMotors(int one, int two)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two);
}

//three motors
void assignStraffDriveMotors(int one, int two, int three)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three);
}

//four motors
void assignStraffDriveMotors(int one, int two, int three, int four)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four);
}

//five motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five);
}

//six motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five, six);
}

//seven motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five, six, seven);
}

//eight motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five, six, seven, eight);
}

//nine motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five, six, seven, eight, nine);
}

//ten motors
void assignStraffDriveMotors(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Motor System");

	//assign motor ports
	assignMotorSystem(straffDrive, one, two, three, four, five, six, seven, eight, nine, ten);
}

#endif
