/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     required_sensor_assignments.h                                */
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
#ifndef _REQUIRED_SENSOR_ASSIGNMENTS_H
#define _REQUIRED_SENSOR_ASSIGNMENTS_H

#pragma systemFile

#include "port_object.h"

//Initialize Required Sensors
sensor turnSensor;
sensor liftSensor;
sensor rightDriveSensor;
sensor leftDriveSensor;
sensor straffDriveSensor;

//assign the turn sensor to desired ports
void assignTurnSensor();
void assignTurnSensor(int port);

//assign the lift sensor to desired ports
void assignLiftSensor();
void assignLiftSensor(int type, int port);
void assignLiftSensor(int type, int portMain, int portSub1);

//assign right drive sensor to desired ports
void assignRightDriveSensor();
void assignRightDriveSensor(int type, int port);
void assignRightDriveSensor(int type, int portMain, int portSub1);

//assign left drive sensor to desired ports
void assignLeftDriveSensor();
void assignLeftDriveSensor(int type, int port);
void assignLeftDriveSensor(int type, int portMain, int portSub1);

//assign straffing drive sensor to desired ports
void assignStraffDriveSensor();
void assignStraffDriveSensor(int type, int port);
void assignStraffDriveSensor(int type, int portMain, int portSub1);

/***************************************************************************************
Function: assignTurnSensor(int)
Purpose: assign sensor for turning
Entry Conditions: port - port desired for sensor
Exit Conditions: NONE
Global: turnSensor - struct holding turn sensor information
Special Note: only can use gyro sensor type, 2 overloaded functions
***************************************************************************************/
//no sensor
void assignTurnSensor()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Turn Sensor");
	writeDebugStreamLine("Ports: NONE");

	//no turn sensor assignment
	resetSensor(turnSensor);
}

//one sensor
void assignTurnSensor(int port)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Turn Sensor");

	//assign the sensor port(s)
	assignSensor(turnSensor, sensorGyro, port);
}

/***************************************************************************************
Function: assignLiftSensor(int, ... int)
Purpose: assign sensor for lift system
Entry Conditions:
port... - port desired for sensor
type - desired sensor type
Exit Conditions: NONE
Global: liftSensor - struct holding lift sensor information
Special Note: 3 overloaded functions
***************************************************************************************/
//no sensor
void assignLiftSensor()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Lift Sensor");
	writeDebugStreamLine("Ports: NONE");

	//no lift sensor assignment
	resetSensor(liftSensor);
}

//sensor uses one sensor port
void assignLiftSensor(int type, int port)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Lift Sensor");

	//assign the sensor port(s)
	assignSensor(liftSensor, type, port);
}

//sensor uses two sensor ports
void assignLiftSensor(int type, int portMain, int portSub1)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Lift Sensor");

	//assign the sensor port(s)
	assignSensor(liftSensor, type, portMain, portSub1);
}

/***************************************************************************************
Function: assignRightDriveSensor(int, ... int)
Purpose: assign sensor for right drive
Entry Conditions:
port... - port desired for sensor
type - desired sensor type
Exit Conditions: NONE
Global: rightDriveSensor - struct holding right drive sensor information
Special Note: 3 overloaded functions
***************************************************************************************/
//no sensor
void assignRightDriveSensor()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Right Drive Sensor");
	writeDebugStreamLine("Ports: NONE");

	//no right drive sensor
	resetSensor(rightDriveSensor);
}

//sensor uses one sensor port
void assignRightDriveSensor(int type, int port)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Right Drive Sensor");

	//assign the sensor port(s)
	assignSensor(rightDriveSensor, type, port);
}

//sensor uses two sensor ports
void assignRightDriveSensor(int type, int portMain, int portSub1)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Right Drive Sensor");

	//assign the sensor port(s)
	assignSensor(rightDriveSensor, type, portMain, portSub1);
}

/***************************************************************************************
Function: assignLeftDriveSensor(int, ... int)
Purpose: assign sensor for left drive
Entry Conditions:
port... - port desired for sensor
type - desired sensor type
Exit Conditions: NONE
Global: leftDriveSensor - struct holding left drive sensor information
Special Note: 3 overloaded functions
***************************************************************************************/
//no sensor
void assignLeftDriveSensor()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Left Drive Sensor");
	writeDebugStreamLine("Ports: NONE");

	//no left drive sensor
	resetSensor(leftDriveSensor);
}

//sensor uses one sensor port
void assignLeftDriveSensor(int type, int port)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Left Drive Sensor");

	//assign the sensor port(s)
	assignSensor(leftDriveSensor, type, port);
}

//sensor uses two sensor ports
void assignLeftDriveSensor(int type, int portMain, int portSub1)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Left Drive Sensor");

	//assign the sensor port(s)
	assignSensor(leftDriveSensor, type, portMain, portSub1);
}

/***************************************************************************************
Function: assignStraffDriveSensor(int, ... int)
Purpose: assign sensor for straffing drive
Entry Conditions:
port... - port desired for sensor
type - desired sensor type
Exit Conditions: NONE
Global: straffDriveSensor - struct holding left drive sensor information
Special Note: 3 overloaded functions
***************************************************************************************/
//no sensor
void assignStraffDriveSensor()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Sensor");
	writeDebugStreamLine("Ports: NONE");

	//no left drive sensor
	resetSensor(straffDriveSensor);
}

//sensor uses one sensor port
void assignStraffDriveSensor(int type, int port)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Sensor");

	//assign the sensor port(s)
	assignSensor(straffDriveSensor, type, port);
}

//sensor uses two sensor ports
void assignStraffDriveSensor(int type, int portMain, int portSub1)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Straff Drive Sensor");

	//assign the sensor port(s)
	assignSensor(straffDriveSensor, type, portMain, portSub1);
}

#endif
