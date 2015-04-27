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
#ifndef _LCD_COMPETITION_SWITCH_H
#define _LCD_COMPETITION_SWITCH_H

#pragma systemFile
#include "lcd_commands.h"

void lcdCompetitionSwitch();

void lcdCompetitionSwitch()
{
	if (bIfiAutonomousMode)
	{
		displayNextLCDString("Autonomous");
		startTask(autonomous);

		// Waiting for autonomous phase to end
		while (bIfiAutonomousMode && !bIfiRobotDisabled)
		{
			if (!bVEXNETActive)
			{
				if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
					allMotorsOff();
			}
			wait1Msec(25);               // Waiting for autonomous phase to end
		}
		allMotorsOff();
		if(bStopTasksBetweenModes)
		{
			allTasksStop();
		}
	}

	else
	{
		displayNextLCDString("User Control");
		startTask(usercontrol);

		// Here we repeat loop waiting for user control to end and (optionally) start
		// of a new competition run
		while (!bIfiAutonomousMode && !bIfiRobotDisabled)
		{
			if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
				allMotorsOff();
			wait1Msec(25);
		}
		allMotorsOff();
		if(bStopTasksBetweenModes)
		{
			allTasksStop();
		}
	}
}

#endif
