/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     sensor_commands.h                                            */
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
#ifndef _SENSOR_COMMANDS_H
#define _SENSOR_COMMANDS_H

#pragma systemFile

#include "port_assignments.h"

//set a sensor to a desired value
void setSensorValue(int value, sensor& target);

//set an array  of sensor to a desired value
void setSensorValue(int value, sensorArray& target);

//set a sensor's value to zero
void zeroSensor(sensor& target);

//set a sensor array's value to zero
void zeroSensor(sensorArray& target);

//return the sensor value
int getSensorValue(sensor& target);

//return a proportional integral derivative value
float pid(float constant, int target, int currentValue);

//get the value of the X axis of an accelerometer
float xAccelerometerValue(sensor& accelerometer);

//get the value of the Y axis of an accelerometer
float yAccelerometerValue(sensor& accelerometer);

//get the value of the Z axis of an accelerometer
float zAccelerometerValue(sensor& accelerometer);

//determine the X axis velocity of an accelerometer
float xAccelerometerVelocity(sensor& accelerometer);

//determine the Y axis velocity of an accelerometer
float yAccelerometerVelocity(sensor& accelerometer);

//determine the Z axis velocity of an accelerometer
float zAccelerometerVelocity(sensor& accelerometer);

/***************************************************************************************
Function: setSensorValue(int, sensor)
Purpose: set a sensor to a desired value
Entry Conditions:
value - the desired sensor value
target - the target sensor
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void setSensorValue(int value, sensor& target)
{
	//set sensor to desired value
	SensorValue[target.portMain] = value;
	SensorValue[target.portSub1] = value;
	SensorValue[target.portSub2] = value;
}

/***************************************************************************************
Function: setSensorValue(int, sensorArray)
Purpose: set an array of sensors to a desired value
Entry Conditions:
value - the desired sensor value
target - the target sensor array
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void setSensorValue(int value, sensorArray& target)
{
	//set sensors to desired value
	for(int i = 0; i < target.sensorAmt; i++)
		setSensorValue(value, target.sensors[i]);
}

/***************************************************************************************
Function: setSensorValue(int, sensor)
Purpose: set a sensor to zero
Entry Conditions:
value - the desired sensor value
target - the target sensor
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void zeroSensor(sensor& target)
{
	//set sensor value to zero
	setSensorValue(0, target);
}

/***************************************************************************************
Function: setSensorValue(int, sensor)
Purpose: set an array of sensors to zero
Entry Conditions:
value - the desired sensor value
target - the target sensor array
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void zeroSensor(sensorArray& target)
{
	//set sensor values to zero
	setSensorValue(0, target);
}

/***************************************************************************************
Function: pid(double, int, int)
Purpose: return a proportional integral derivative value
Entry Conditions:
currentValue - the current value being read from
target - the target value to be reached
constant - the ratio upon which the error is being multiplied by
Exit Conditions: pidValue - the current pid value
Global: NONE
Special Note: Can be used to give motor values
***************************************************************************************/
float pid(float constant, int target, int currentValue)
{
	//PID algorithm
	float error = (target - currentValue);
	float pidValue = (error * constant);

	return pidValue;
}

/***************************************************************************************
Function: int getSensorValue(sensor)
Purpose: returns the sensor value
Entry Conditions: target - sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
int getSensorValue(sensor& target)
{
	//get the current sensor value
	return SensorValue[target.portMain];
}

/***************************************************************************************
Function: isPressed(sensor)
Purpose: returns true if a contact switch was pressed
Entry Conditions: button - a touch sensor
Exit Conditions: NONE
Global:NONE
Special Note: Uses vexNET joystick. Can only use during teleOp
2 overloaded functions
***************************************************************************************/
bool isPressed(sensor& button)
{
	//button is pressed
	if(getSensorValue(button) == 1)
		return true;

	//button is not pressed
	else
		return false;
}

/***************************************************************************************
Function: xAccelerometerValue(int)
Purpose: get the value of the X axis of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float xAccelerometerValue(sensor& accelerometer)
{
	//get the x accelerometer value
	return SensorValue[accelerometer.portMain];
}

/***************************************************************************************
Function: yAccelerometerValue(int)
Purpose: get the value of the Y axis of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float yAccelerometerValue(sensor& accelerometer)
{
	//get the y accelerometer value
	return SensorValue[accelerometer.portSub1];
}

/***************************************************************************************
Function: zAccelerometerValue(int)
Purpose: get the value of the Z axis of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float zAccelerometerValue(sensor& accelerometer)
{
	//get the z accelerometer value
	return SensorValue[accelerometer.portSub2];
}

/***************************************************************************************
Function: xAccelerometerVelocity(int)
Purpose: determine the X axis velocity of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float xAccelerometerVelocity(sensor& accelerometer)
{
	//get sample time
	wait1Msec(1);

	//calculate velocity
	return (xAccelerometerValue(accelerometer)/1000);
}

/***************************************************************************************
Function: yAccelerometerVelocity(int)
Purpose: determine the Y axis velocity of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float yAccelerometerVelocity(sensor& accelerometer)
{
	//get sample time
	wait1Msec(1);

	//calculate velocity
	return (yAccelerometerValue(accelerometer)/1000);
}

/***************************************************************************************
Function: zAccelerometerVelocity(int)
Purpose: determine the Z axis velocity of an accelerometer
Entry Conditions: accelerometer - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: NONE
***************************************************************************************/
float zAccelerometerVelocity(sensor& accelerometer)
{
	//get sample time
	wait1Msec(1);

	//calculate velocity
	return (zAccelerometerValue(accelerometer)/1000);
}

#endif
