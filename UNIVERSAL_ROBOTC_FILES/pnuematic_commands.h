/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     pnuematic_commands.h                                         */
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
#ifndef _PNUEMATIC_COMMANDS_H
#define _PNUEMATIC_COMMANDS_H

#pragma systemFile

#include "port_object.h"
#include "sensor_commands.h"

/*pnuematic command prototypes*/
//extend one piston
void extend(sensor& target);

//extend an array of pistons
void extend(sensorArray& target);

//extend one piston for a desired amount of time
void extendFor(int time, sensor& target);

//extend an array of pistons for a desired amount of time
void extendFor(int time, sensorArray& target);

//retract one piston
void retract(sensor& target);

//retract an array of pistons
void retract(sensorArray& target);

//retract one piston for a desired amount of time
void retractFor(int time, sensor& target);

//retract an array of pistons for a desired amount of time
void retractFor(int time, sensorArray& target );

/***************************************************************************************
Function: extend(sensor)
Purpose: extend one piston
Entry Conditions: target - the target desired sensor
Exit Conditions: NONE
Global: NONE
Special Note: must have a sensor of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void extend(sensor& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Pneumatic actuator extended");

	//engage the piston
	setSensorValue(1, target);
}

/***************************************************************************************
Function: extend(sensorArray&)
Purpose: extend an array of pistons
Entry Conditions: target - the target desired sensor Array
Exit Conditions: NONE
Global: NONE
Special Note: must have a sensor of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void extend(sensorArray& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Pneumatic actuator system extended");

	//engage the pistons
	setSensorValue(1, target);
}

/***************************************************************************************
Function: extendFor(sensor&, int)
Purpose: extend one piston for a desired amount of time
Entry Conditions:
target - the target desired sensor
time - the amount of time in milliseconds
Exit Conditions: NONE
Global: NONE
Special Note: must have a sensor of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void extendFor(int time, sensor& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Pneumatic actuator extended for %d", time);
	writeDebugStreamLine("ms");

	//engage the piston
	zeroSensor(target);

	//wait for desired time
	wait1Msec(time);

	//disengage the piston
	setSensorValue(1, target);
}

/***************************************************************************************
Function: void extendFor(int ,sensorArray&)
Purpose: extend an array of pistons for a desired amount of time
Entry Conditions:
target - the target desired sensor
time - the amount of time in milliseconds
Exit Conditions: NONE
Global: NONE
Special Note: must have sensors of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void extendFor(int time, sensorArray& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Pneumatic actuator system extended for %d", time);
	writeDebugStreamLine("ms");

	//engage the piston
	zeroSensor(target);

	//wait for desired time
	wait1Msec(time);

	//disengage the piston
	setSensorValue(1, target);
}

/***************************************************************************************
Function: retract(sensor&)
Purpose: retract one piston
Entry Conditions: target - the target desired sensor
Exit Conditions: NONE
Global: NONE
Special Note: must have a sensor of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void retract(sensor& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Pneumatic actuator retracted");

	//disengage the piston
	zeroSensor(target);
}

/***************************************************************************************
Function: void retract(sensorArray&)
Purpose: retract an array of pistons
Entry Conditions: target - the target desired sensor Array
Exit Conditions: NONE
Global: NONE
Special Note: must have sensors of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void retract(sensorArray& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Pneumatic actuator system retracted");

	//disengage the pistons
	zeroSensor(target);
}

/***************************************************************************************
Function: retractFor(sensor&, int)
Purpose: retract one piston for a desired amount of time
Entry Conditions:
target - the target desired sensor
time - the amount of time in milliseconds
Exit Conditions: NONE
Global: NONE
Special Note: must have a sensor of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void retractFor(int time, sensor& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Pneumatic actuator retracted for %d", time);
	writeDebugStreamLine("ms");

	//disengage the piston
	zeroSensor(target);

	//wait for desired time
	wait1Msec(time);

	//engage the piston
	setSensorValue(1, target);
}

/***************************************************************************************
Function: retractFor(int ,sensorArray&)
Purpose: retract on array of pistons for a desired amount of time
Entry Conditions:
target - the target desired sensor
time - the amount of time in milliseconds
Exit Conditions: NONE
Global: NONE
Special Note: must have sensors of type sensorDigitalOut
2 overloaded functions
***************************************************************************************/
void retractFor(int time, sensorArray& target )
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Pneumatic actuator system retracted for %d", time);
	writeDebugStreamLine("ms");

	//disengage the piston
	zeroSensor(target);

	//wait for desired time
	wait1Msec(time);

	//engage the piston
	setSensorValue(1, target);
}

#endif
