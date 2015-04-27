/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     intake_commands.h                                            */
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
#ifndef _INTAKE_COMMANDS_H
#define _PORT_ASSIGNMENTS_H

#pragma systemFile

#include "port_assignments.h"
#include "motor_commands.h"

//stop the intake
void stopIntake();

//intake objects
void intake();

//intake for a desired amount of time
void intakeFor(int time);

//eject objects
void eject();

//eject for a desired amount of time
void ejectFor(int time);

/***************************************************************************************
Function: stopIntake()
Purpose: the intake is set to stop
Entry Conditions: NONE
Exit Conditions: NONE
Global:intakeSystem - the intake motor system
Special Note: NONE
***************************************************************************************/
void stopIntake()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Intake disabled");

	//stop intake motors
	halt(intakeSystem);
}

/***************************************************************************************
Function: intake()
Purpose: the intake is set to intake objects
Entry Conditions: NONE
Exit Conditions: NONE
Global:intakeSystem - the intake motor system
Special Note: NONE
***************************************************************************************/
void intake()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Intake In");

	//intake objects
	run(127, intakeSystem);
}

/***************************************************************************************
Function: intakeFor(int)
Purpose: the intake is set to intake objects for a desired amount of time
Entry Conditions: time - amount of time in milliseconds
Exit Conditions: NONE
Global:intakeSystem - the intake motor system
Special Note: NONE
***************************************************************************************/
void intakeFor(int time)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Intake In For: %d", time);
	writeDebugStreamLine("ms");

	//intake objects
	run(127, intakeSystem);

	//wait for desired amount of time
	wait1Msec(time);

	//stop intake
	halt(intakeSystem);
}

/***************************************************************************************
Function: eject()
Purpose: the intake is set to eject objects
Entry Conditions: NONE
Exit Conditions: NONE
Global:intakeSystem - the intake motor system
Special Note: NONE
***************************************************************************************/
void eject()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Intake Out");

	//intake objects
	run(-127, intakeSystem);
}

/***************************************************************************************
Function: ejectFor(int)
Purpose: the intake is set to eject objects for a desired amount of time
Entry Conditions: time - amount of time in milliseconds
Exit Conditions: NONE
Global:intakeSystem - the intake motor system
Special Note: NONE
***************************************************************************************/
void ejectFor(int time)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStream("Intake Out For: %d", time);
	writeDebugStreamLine("ms");

	//intake objects
	run(-127, intakeSystem);

	//wait for desired amount of time
	wait1Msec(time);

	//stop intake
	halt(intakeSystem);
}

#endif
