/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     motor_commands.h                                             */
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
#ifndef _MOTOR_COMMANDS_H
#define _MOTOR_COMMANDS_H

#pragma systemFile

#include "port_assignments.h"
#include "sensor_commands.h"

//set motor value to zero
void halt(int port);

//set all the motor values in the system to zero
void halt(motorSystem& target);

//run motor at a desired velocity
void run(int velocity, int& port);

//run motor system motors at a desired velocity
void run(int velocity, motorSystem& target);

//run a motor for a desired amount of time at a desired velocity
void runFor(int velocity, int time, int& port);

//run a motor system for a desired amount of time at a desired velocity
void runFor(int velocity, int time, motorSystem& target);

//run a motor at a desired speed for a desired amount of time until
//a target value has been reached by the sensor
void runToTarget(int velocity, int& port, int value, sensor& witness);

//run a motor system at a desired speed for a desired amount of time until
//a target value has been reached by the sensor
void runToTarget(int velocity, motorSystem& target, int value, sensor& witness);

/***************************************************************************************
Function: run(int, int&)
Purpose: run motor at a desired velocity
Entry Conditions:
velocity - the desired velocity to run the motor at
port - the target motor port
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void run(int velocity, int& port)
{
	//set velocity for motor
	motor[port] = velocity;
}

/***************************************************************************************
Function: run(int, motorSystem&)
Purpose: run motor system motors at a desired velocity
Entry Conditions:
velocity - the desired velocity to run the motor at
target - the target motor System
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void run(int velocity, motorSystem& target)
{
	//set velocity for motor in motor system
	for(int i = 0; i < target.motorAmt; i++)
		run(velocity, target.motors[i]);
}

/***************************************************************************************
Function: halt(int&)
Purpose: set motor value to zero
Entry Conditions: port - the target motor port
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void halt(int& port)
{
	//set motor port to zero
	run(0, port);
}

//
/***************************************************************************************
Function: halt(motorSystem&)
Purpose: set all the motor values in the system to zero
Entry Conditions: target - the target motor system
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void halt(motorSystem& target)
{
	//set all motors to zero
	run(0, target);
}

/***************************************************************************************
Function: runFor(int, int, int&)
Purpose: run a motor for a desired amount of time in milliseconds at a desired velocity
Entry Conditions:
velocity - the desired velocity to run the motor at
time - the amount of time in milliseconds
port - the target motor port
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void runFor(int velocity, int time, int& port)
{
	//set motor value
	run(velocity, port);

	//run for desired time
	wait1Msec(time);

	//stop the emotor
	halt(port);
}

/***************************************************************************************
Function: runFor(int, int, motorSystem&)
Purpose: run a motor System for a desired amount of time
in milliseconds at a desired velocity
Entry Conditions:
velocity - the desired velocity to run the motor at
time - the amount of time in milliseconds
target - the target motor system
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void runFor(int velocity, int time, motorSystem& target)
{
	//set motor system motor values
	run(velocity, target);

	//run for desired time
	wait1Msec(time);

	//stop the motor system's motors
	halt(target);
}

/***************************************************************************************
Function: runToTarget(int, int&, int, sensor&)
Purpose: run a motor at a desired speed for a desired amount of time until
a target value has been reached by the sensor
Entry Conditions:
velocity - the desired velocity to run the motor at
value - target sensor value
port - the target motor
witness - the sensor that is observeing
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void runToTarget(int velocity, int port, int value, sensor& witness)
{
	//reset the sensor value
	zeroSensor(witness);

	//run the motor untill target sensor value
	while(abs(SensorValue[witness]) < abs(value))
		run(velocity, port);

	//stop the motor
	halt(port);
}

/***************************************************************************************
Function: runToTarget(int, motorSystem&, int, sensor&)
Purpose: run a motor system at a desired speed for a desired amount of time until
a target value has been reached by the sensor
Entry Conditions:
velocity - the desired velocity to run the motor at
value - target sensor value
target - the target motor System
witness - the sensor that is observeing
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void runToTarget(int velocity, motorSystem& target, int value, sensor& witness)
{
	//reset the sensor value
	zeroSensor(witness);

	//run the motor untill target sensor value
	while(abs(SensorValue[witness]) < abs(value))
		run(velocity, target);

	//stop the motor
	halt(target);
}

#endif
