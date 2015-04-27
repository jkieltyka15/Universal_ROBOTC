/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     lcd_commands.h                                               */
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
#ifndef _LCD_COMMANDS_H
#define _LCD_COMMANDS_H

#pragma systemFile

#include "port_assignments.h"
#include "sensor_commands.h"

//returns true if the desired lcd buttion is pressed
bool lcdButtonIsPressed(int button);

//clear LCD Screen
void clearLCDScreen();

//wait for an LCD button to be released
void waitForRelease();

//Display the current value of the sensor port
void lcdSensorInfo(string name, sensor& target);

//Display autonomous selection menu
void lcdAutonomousMenu();

//Display utility menu
void lcdUtilityMenu();

//Display competition menu
void lcdCompetitionMenu();

/***************************************************************************************
Function: clearLCDScreen()
Purpose: returns true if the desired lcd buttion is pressed
Entry Conditions: button - target lcd button
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
bool lcdButtonIsPressed(int button)
{
	//button is pressed
	if(button == nLCDButtons)
	{
		//debug stream
		writeDebugStreamLine(" ");
		writeDebugStream("Button Pressed: ");
		switch(button)
		{
			//Left LCD Button
		case leftButton:
			writeDebugStreamLine("Left LCD");
			break;

			//Center LCD Button
		case centerButton:
			writeDebugStreamLine("Center LCD");
			break;

			//Right LCD Button
		case rightButton:
			writeDebugStreamLine("Right LCD");
			break;
		}

		//button was pressed
		return true;
	}

	//button is not pressed
	else
		return false;
}

/***************************************************************************************
Function: clearLCDScreen()
Purpose: clear LCD Screen
Entry Conditions: NONE
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void clearLCDScreen()
{
	//clear the current LCD line
	for(int i = 0; i < 2; i++)
		clearLCDLine(i);
}

/***************************************************************************************
Function: waitForRelease()
Purpose: wait for an LCD button to be released
Entry Conditions: NONE
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void waitForRelease()
{
	//wait for lcd button values to equal zero
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

/***************************************************************************************
Function: lcdSensorInfo(string, sensor&)
Purpose: Display the current value of the sensor port
Entry Conditions:
name - the name of the sensor
target - the sensor being observed
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void lcdSensorInfo(string name, sensor& target)
{
	//clear the LCD
	clearLCDScreen();

	//Display the Sensor Value
	displayLCDCenteredString(0, name);
	displayLCDString(1, 0, "Value:");
	displayLCDNumber(1, 7, getSensorValue(target));
}

/***************************************************************************************
Function: lcdAutonomousMenu()
Purpose: Display autonomous selection menu
Entry Conditions: NONE
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void lcdAutonomousMenu()
{
	//clear LCD Screen
	clearLCDScreen();

	//Reset Alliance
	alliance = NONE;

	//Reset Starting Tile
	startingTile = "NONE";

	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Autonomous selection menu queued");

	//Display alliance choices, press center button to skip
	while(alliance == NONE && !lcdButtonIsPressed(centerButton))
	{
		//display alliance options
		displayLCDCenteredString(0, "SELECT ALLIANCE");
		displayLCDCenteredString(1, "x");
		displayLCDString(1,0, "RED");
		displayLCDString(1,11, "BLUE");

		//select red alliance
		if(lcdButtonIsPressed(leftButton))
		{
			//debug stream
			writeDebugStreamLine("Alliance: Red");

			//assign red alliance
			alliance = RED;
			waitForRelease();
		}

		//select blue alliance
		else if(lcdButtonIsPressed(rightButton))
		{
			//debug stream
			writeDebugStreamLine("Alliance: Blue");

			//assign blue alliance
			alliance = BLUE;
			waitForRelease();
		}

		//allow data to be displayed
		wait1Msec(50);
	}

	//clear LCD Screen
	clearLCDScreen();

	//display starting position options, press center button to skip
	while(startingTile == "NONE" && !lcdButtonIsPressed(centerButton))
	{
		//display position options
		displayLCDCenteredString(0, "SELECT POSITON");
		displayLCDCenteredString(1, "x");
		displayLCDString(1,0, position1);
		displayLCDString(1,15 - strlen(position2), position2);

		//select position 1
		if(lcdButtonIsPressed(leftButton))
		{
			//debug stream
			writeDebugStream("Starting Position: ");
			writeDebugStreamLine(position1);

			//starting tile is assigned as position 1
			startingTile = position1;

			//wait for LCD button to be released
			waitForRelease();
		}

		//select position 2
		else if(lcdButtonIsPressed(rightButton))
		{
			//debug stream
			writeDebugStream("Starting Position: ");
			writeDebugStreamLine(position2);

			//starting tile is assigned as position 2
			startingTile = position2;

			//wait for LCD bytton to be released
			waitForRelease();
		}

		//allow data to be displayed
		wait1Msec(50);
	}
}

/***************************************************************************************
Function: lcdUtilityMenu()
Purpose: Display utility selection menu
Entry Conditions: NONE
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void lcdUtilityMenu()
{
	int value = 0;

	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Utility menu queued");

	//select a sensor to view, press LCD center button
	//to exit
	while(!lcdButtonIsPressed(centerButton))
	{
		//LCD Left Button Control
		if(lcdButtonIsPressed(leftButton))
		{
			//go to last sensor
			if(value == 0)
				value = 3;

			//go to next sensor
			else
				value--;
		}

		//LCD Right Button Control
		else if(lcdButtonIsPressed(rightButton))
		{
			//go to first sensor
			if(value == 3)
				value = 0;

			//go to next sensor
			else
				value++;
		}

		//wait for the button to be released
		waitForRelease();

		//display desired sensor
		string name = "NO SENSOR";
		switch(value)
		{
			//right drive sensor
		case 0:
			name = "RIGHT DRIVE";
			lcdSensorInfo(name, rightDriveSensor);
			break;

			//left drive sensor
		case 1:
			name = "LEFT DRIVE";
			lcdSensorInfo(name, leftDriveSensor);
			break;

			//lift sensor
		case 2:
			name = "LIFT";
			lcdSensorInfo(name, liftSensor);
			break;

			//turn sensor
		case 3:
			name = "TURN GYRO";
			lcdSensorInfo(name, turnSensor);
			break;
		}

		//allow data to be displayed
		wait1Msec(50);
	}
	//wait for the button to be released
	waitForRelease();
}

/***************************************************************************************
Function: lcdCompetitionMenu()
Purpose: Display competition selection menu
Entry Conditions: NONE
Exit Conditions: NONE
Global:NONE
Special Note: Uses LCD
***************************************************************************************/
void lcdCompetitionMenu()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Competition menu queued");

	//continue untill an alliance and staring position has been selected
	while(alliance == NONE || startingTile == "NONE")
	{
		//clear LCD
		clearLCDScreen();

		//set value to none
		int value = NONE;

		//Select a Menu
		displayLCDCenteredString(0,"MENU SELECT");
		displayLCDString(1, 0, "AUTO");
		displayLCDString(1, 10, "SENSOR");

		//wait for a button to be pressed
		while(value == NONE)
		{
			//select autonomous menu
			if(lcdButtonIsPressed(leftButton))
				value = 0;

			//select utility menu
			else if(lcdButtonIsPressed(rightButton))
				value = 1;
		}

		//wait for the button to be released
		waitForRelease();

		//select a menu
		switch(value)
		{
			//Autonomous Selection
		case 0:
			lcdAutonomousMenu();
			break;

			//View Sensors
		case 1:
			lcdUtilityMenu();
			break;
		}

		//allow data to be displayed
		wait1Msec(50);
	}

	//debug stream
	writeDebugStreamLine("Competition selections completed");
}

#endif
