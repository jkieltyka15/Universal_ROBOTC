/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     controller_commands.h                                        */
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
#ifndef _JOYSTICK_COMMANDS_H
#define _JOYSTICK_COMMANDS_H

#pragma systemFile

#include "port_assignments.h"
#include "motor_commands.h"

//Allows an operator to control the robot using joysticks
void driveControlJoysticks(int controller);

//returns true if a button is pressed
bool isPressed(int button);

/***************************************************************************************
Function: driveControlJoysticks(int, int)
Purpose: Allows an operator to control the robot using joysticks
Entry Conditions: controller - defines the if the controller is the
main or partner controller
Exit Conditions: NONE
Global:
X_DRIVE - a value that represents an X-Drive style robot
TANK_DRIVE - a value that represents a Tank-Drive style robot
H_DRIVE - a value that represents an H-Drive
Special Note: Joystick control
***************************************************************************************/
void driveControlJoysticks(int controller)
{
	//X-Drive TeleOp
	if(driveType == X_DRIVE)
	{
		//right drive
		for(int i = 0; i < rightDrive.motorAmt; i++)
		{
			//main controller
			if(controller == MAIN)
			{
				//front right
				run((vexRT[Ch3] - vexRT[Ch4] - vexRT[Ch1]*xDriveMotorTrim), rightDrive.motors[i]);

				//back right
				run((vexRT[Ch3] + vexRT[Ch4] - vexRT[Ch1]*xDriveMotorTrim), rightDrive.motors[++i]);
			}

			//partner controller
			else
			{
				//front right
				run((vexRT[Ch3Xmtr2] - vexRT[Ch4Xmtr2] - vexRT[Ch1Xmtr2]*xDriveMotorTrim), rightDrive.motors[i]);

				//back right
				run((vexRT[Ch3Xmtr2] + vexRT[Ch4Xmtr2] - vexRT[Ch1Xmtr2]*xDriveMotorTrim), rightDrive.motors[++i]);
			}
		}

		//left drive
		for(int i = 0; i < leftDrive.motorAmt; i++)
		{
			//main controller
			if(controller == MAIN)
			{
				//front left
				run((vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1]*xDriveMotorTrim), leftDrive.motors[i]);

				//back left
				run((vexRT[Ch3] - vexRT[Ch4] + vexRT[Ch1]*xDriveMotorTrim), leftDrive.motors[++i]);
			}

			//partner controller
			else
			{
				//front left
				run((vexRT[Ch3Xmtr2] + vexRT[Ch4Xmtr2] + vexRT[Ch1Xmtr2]*xDriveMotorTrim), leftDrive.motors[i]);

				//back left
				run((vexRT[Ch3Xmtr2] - vexRT[Ch4Xmtr2] + vexRT[Ch1Xmtr2]*xDriveMotorTrim), leftDrive.motors[++i]);
			}
		}
	}

	//Tank-Drive TeleOp
	else if(driveType == H_DRIVE || driveType == TANK_DRIVE)
	{
		//right drive
		for(int i = 0; i < rightDrive.motorAmt; i++)
		{
			//main controller
			if(controller == MAIN)
				run(vexRT[Ch2], rightDrive);

			//partner controller
			else
				run(vexRT[Ch2Xmtr2], rightDrive);
		}

		//left drive
		for(int i = 0; i < leftDrive.motorAmt; i++)
		{
			//main controller
			if(controller == MAIN)
				run(vexRT[Ch3], leftDrive);

			//partner controller
			else
				run(vexRT[Ch3Xmtr2], leftDrive);
		}

		//straff drive
		if(driveType == H_DRIVE)
			for(int i = 0; i < straffDrive.motorAmt; i++)
		{
			//main controller
			if(controller == MAIN)
				run(vexRT[Ch1], straffDrive);

			//partner controller
			else
				run(vexRT[Ch1Xmtr2], straffDrive);
		}
	}
}

/***************************************************************************************
Function: isPressed(int)
Purpose: returns true if a joystick button was pressed
Entry Conditions: button - vex net joystick button
Exit Conditions: NONE
Global:NONE
Special Note: Uses vexNET joystick. Can only use during teleOp
2 overloaded functions
***************************************************************************************/
bool isPressed(int button)
{
	//button is pressed
	if(vexRT[button] == 1)
	{
		//debug stream
		writeDebugStreamLine(" ");
		writeDebugStream("Button Pressed: ");

		switch(button)
		{
			//target button is 5D
		case Btn5D:
			writeDebugStreamLine("5D");
			break;

			//target button is 5U
		case Btn5U:
			writeDebugStreamLine("5U");
			break;

			//target button is 6D
		case Btn6D:
			writeDebugStreamLine("6D");
			break;

			//target button is 6U
		case Btn6U:
			writeDebugStreamLine("6U");
			break;

			//target button is 7D
		case Btn7D:
			writeDebugStreamLine("7D");
			break;

			//target button is 7U
		case Btn7U:
			writeDebugStreamLine("7U");
			break;

			//target button is 7L
		case Btn7L:
			writeDebugStreamLine("7L");
			break;

			//target button is 7R
		case Btn7R:
			writeDebugStreamLine("7R");
			break;

			//target button is 8D
		case Btn8D:
			writeDebugStreamLine("8D");
			break;

			//target button is 8U
		case Btn8U:
			writeDebugStreamLine("8U");
			break;

			//target button is 8L
		case Btn8L:
			writeDebugStreamLine("8L");
			break;

			//target button is 8R
		case Btn8R:
			writeDebugStreamLine("8R");
			break;
		}

		//target button was pressed
		return true;
	}

	//button is not pressed
	else
		return false;
}

#endif
