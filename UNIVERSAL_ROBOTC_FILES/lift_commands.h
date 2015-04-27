/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     lift_commands.h                                              */
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
#ifndef _LIFT_COMMANDS_H
#define _LIFT_COMMANDS_H

#pragma systemFile

#include "port_object.h"

//go to the lift position
void goToLiftPosition(int position);

//go in the direction of the lift position
void goTowardsLiftPosition(int position);

/***************************************************************************************
Function: goToLiftPosition(int)
Purpose: go to the desired lift position
Entry Conditions: position - the target lift position value
Exit Conditions: NONE
Global: NONE
Special Note: NONE
***************************************************************************************/
void goToLiftPosition(int position)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Going to lift position");
	writeDebugStreamLine("Position: %d", position);

	//the target lift position has not been reached
	while(abs(getSensorValue(liftSensor)) != position ||
		abs(pid(liftMotorTrim, position, abs(getSensorValue(liftSensor)))) > 10)
	run(pid(liftMotorTrim, position, abs(getSensorValue(liftSensor))), liftSystem);

	//stop the lift motors
	halt(liftSystem);
}

/***************************************************************************************
Function: goTowardsLiftPosition(int)
Purpose: go towards the desired lift position
Entry Conditions: position - the target lift position value
Exit Conditions: NONE
Global: NONE
Special Note: Highly suggest to be used within  a "while" loop
***************************************************************************************/
void goTowardsLiftPosition(int position)
{
	//the target lift position has not been reached
	if(abs(getSensorValue(liftSensor)) != position)
		run(pid(liftMotorTrim, position, abs(getSensorValue(liftSensor))), liftSystem);

	//stop the lift motors
	else
		halt(liftSystem);
}

#endif
