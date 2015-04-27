/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) Jordan Kieltyka                        */
/*                                    2015                                     */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     port_object.h                                                */
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
#ifndef _PORT_OBJECT_H
#define _PORT_OBJECT_H

#pragma systemFile

#pragma config(I2C_Usage, I2C1, i2cSensors)

//sensor struct
typedef struct
{
	int portMain;
	int portSub1;
	int portSub2;
	int type;
}sensor;

//sensor array struct
typedef struct
{
	sensor sensors[20];
	int sensorAmt;
}sensorArray;

//motor struct
typedef struct
{
	int motors[10];
	int motorAmt;
}motorSystem;

//configure the ports for a sensor
void configureSensor(sensor& target);

//configure the ports for a sensor array
void configureSensor(sensorArray& target);

//reset the target sensor
void resetSensor(sensor& target);

//reset the sensors in the target array
void resetSensor(sensorArray& target);

//no sensor
void assignSensor();

//assign one port for sensor
void assignSensor(sensor& target, int type, int portMain);

//assign two ports for sensor
void assignSensor(sensor& target, int type, int portMain,  int portSub1);

//assign three ports for sensor
void assignSensor(sensor& target, int type, int portMain, int portSub1, int portSub2);

//no sensors to assign in the sensor array
void assignSensorArray();

//one sensor to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one);

//two sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two);

//three sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three);

//four sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four);

//five sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five);

//six sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six);

//seven sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven);

//eight sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight);

//nine sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine);

//ten sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten);

//eleven sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven);

//twelve sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve);

//thirteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen);

//fourteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen);

//fifteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen);

//sixteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen);

//seventeen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen);

//eighteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen);

//nineteen sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen, sensor nineteen);

//twenty sensors to assign in the sensor array
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen, sensor nineteen, sensor twenty);

//reset the motors in the motor system
void resetMotorSystem(motorSystem& target);

//no motors to assign to the motor system
void assignMotorSystem();

//one motor to assign to the motor system
void assignMotorSystem(motorSystem& target, int one);

//two motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two);

//three motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three);

//four motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four);

//five motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five);

//six motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six);

//seven motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven);

//eight motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight);

//nine motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine);

//ten motors to assign to the motor system
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten);

/***************************************************************************************
Function: configureSensor(sensor)
Purpose: configure the ports for a sensor
Entry Conditions: target - the desired sensor to be configured
Exit Conditions: NONE
Global:NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void configureSensor(sensor& target)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Configuring Sensor");
	writeDebugStream("Type: ");

	//debug stream
	switch(target.type)
	{
		//default
	default:
		writeDebugStreamLine("No Sensor");
		break;

		//No sensor
	case sensorNone:
		writeDebugStreamLine("No Sensor");
		break;

	case sensorTouch:
		writeDebugStreamLine("Touch Sensor");
		break;

	case sensorDigitalIn:
		writeDebugStreamLine("Digital In");
		break;

	case sensorDigitalOut:
		writeDebugStreamLine("Digital Out");
		break;

	case sensorDigitalHighImpedance:
		writeDebugStreamLine("Digital High Impedance");
		break;

	case sensorQuadEncoder:
		writeDebugStreamLine("2 Wire Encoder");
		break;

	case sensorQuadEncoderOnI2CPort:
		writeDebugStreamLine("I2C Encoder");
		break;

	case sensorLEDtoVCC:
		writeDebugStreamLine("LED");
		break;

	case sensorSONAR_Ping_cm:
		writeDebugStreamLine("Sonar (cm)");
		break;

	case sensorSONAR_Ping_inch:
		writeDebugStreamLine("Sonar (inches)");
		break;

	case sensorSONAR_Ping_mm:
		writeDebugStreamLine("Sonar (mm)");
		break;

	case sensorSONAR_Ping_raw:
		writeDebugStreamLine("Sonar (raw)");
		break;

	case sensorSONAR_TwoPins_cm:
		writeDebugStreamLine("Sonar (cm)");
		break;

	case sensorSONAR_TwoPins_inch:
		writeDebugStreamLine("Sonar (inches)");
		break;

	case sensorSONAR_TwoPins_mm:
		writeDebugStreamLine("Sonar (mm)");
		break;

	case sensorSONAR_TwoPins_raw:
		writeDebugStreamLine("Sonar (raw)");
		break;

	case sensorAnalog:
		writeDebugStreamLine("Analog");
		break;

	case sensorPotentiometer:
		writeDebugStreamLine("Potentiometer");
		break;

	case sensorLineFollower:
		writeDebugStreamLine("Line Follower");
		break;

	case sensorGyro:
		writeDebugStreamLine("Gyro");
		break;

	case sensorAccelerometer:
		writeDebugStreamLine("Accelerometer");
		break;

	case sensorSpare2OnI2CPort:
		writeDebugStreamLine("Spare 2 I2C");
		break;

	case sensorSpare3OnI2CPort:
		writeDebugStreamLine("Spare 3 I2C");
		break;

	case sensorSpare4OnI2CPort:
		writeDebugStreamLine("Spare 4 I2C");
		break;
	}

	//debug stream
	writeDebugStream("Main Port: ");
	sensorPortAsString(target.portMain);
	writeDebugStreamLine(" ");

	//set up sensor ports
	SensorType[target.portMain] = target.type;

	//accellerometer
	if(target.type == (int)sensorAccelerometer)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");
		writeDebugStream("Sub Port2: ");
		sensorPortAsString(target.portSub2);
		writeDebugStreamLine(" ");

		//assign sensor type to ports
		SensorType[target.portSub1] = target.type;
		SensorType[target.portSub2] = target.type;
	}

	//Quadrature motor encoder (2 pins)
	else if(target.type == (int)sensorQuadEncoder)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");

		//assign sensor type to port
		SensorType[target.portSub1] = sensorQuadEncoderSecondPort;
	}

	//sonar CM (2 pins)
	else if(target.type == (int)sensorSONAR_TwoPins_cm)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");

		//assign sensor type to port
		SensorType[target.portSub1] = sensorSONAR_TwoPins_SecondPort;
	}

	//sonar IN (2 pins)
	else if(target.type == (int)sensorSONAR_TwoPins_inch)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");

		//assign sensor type to port
		SensorType[target.portSub1] = sensorSONAR_TwoPins_SecondPort;
	}

	//sonar MM (2 pins)
	else if(target.type == (int)sensorSONAR_Ping_mm)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");

		//assign sensor type to port
		SensorType[target.portSub1] = sensorSONAR_TwoPins_SecondPort;
	}

	//sonar RAW (2 pins)
	else if(target.type == (int)sensorSONAR_TwoPins_raw)
	{
		//debug stream
		writeDebugStream("Sub Port1: ");
		sensorPortAsString(target.portSub1);
		writeDebugStreamLine(" ");

		//assign sensor type to port
		SensorType[target.portSub1] = sensorSONAR_TwoPins_SecondPort;
	}
}

/***************************************************************************************
Function: configureSensor(sensorArray)
Purpose: configure the ports for a sensor array
Entry Conditions: target - the desired sensor array to be configured
Exit Conditions: NONE
Global:NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void configureSensor(sensorArray& target)
{
	//configure all of the sensors
	for(int i = 0; i < target.sensorAmt; i++)
		configureSensor(target.sensors[i]);
}

/***************************************************************************************
Function: resetSensor(sensor&)
Purpose: reset the sensor
Entry Conditions: target - the sensor to be reset
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void resetSensor(sensor& target)
{
	target.portMain = -1;
	target.portSub1 = -1;
	target.portSub2 = -1;
	target.type = sensorNone;

	//assign type of sensor to ports
	SensorType[target.portMain] = sensorNone;
	SensorType[target.portSub1] = sensorNone;
	SensorType[target.portSub2] = sensorNone;
}

/***************************************************************************************
Function: resetSensor(sensorArray&)
Purpose: reset the desired motor system
Entry Conditions: sensorArray& - the sensorArray& to be reset
Exit Conditions: NONE
Global: NONE
Special Note: 2 overloaded functions
***************************************************************************************/
void resetSensor(sensorArray& target)
{
	//reset all sensors in the sensor array
	for(int i = 0; i < 20; i++)
		resetSensor(target.sensors[i]);

	//set total amount of motors in the system to zero
	target.sensorAmt = 0;
}

/***************************************************************************************
Function: assignSensor(sensor, int , int, int, int)
Purpose: initialize and assign a sensor
Entry Conditions:
sensor - the current sensor being manipulated
portMain - the main sensor port
portSub1 -  a supporting sensor port
portSub2 - a supporting sensor port
Exit Conditions: NONE
Global: NONE
Special Note: NONE
***************************************************************************************/
//no sensor
void assignSensor()
{
	//do nothing
}

//one sensor port needed
void assignSensor(sensor& target, int type, int portMain)
{
	//reset sensor
	resetSensor(target);

	//setup sensor
	target.portMain = portMain;
	target.type = type;

	//assign sensor values to ports
	configureSensor(target);
}

//two sensor ports needed
void assignSensor(sensor& target, int type, int portMain, int portSub1)
{
	//reset sensor
	resetSensor(target);

	//setup sensor
	target.portMain = portMain;
	target.portSub1 = portSub1;
	target.type = type;

	//assign sensor values to ports
	configureSensor(target);
}

//three sensor ports needed
void assignSensor(sensor& target, int type, int portMain, int portSub1, int portSub2)
{
	//reset sensor
	resetSensor(target);

	//setup sensor
	target.portMain = portMain;
	target.portSub1 = portSub1;
	target.portSub2 = portSub2;
	target.type = type;

	//assign sensor values to ports
	configureSensor(target);
}

/***************************************************************************************
Function: assignSensorArray(sensorArray&, sensor...)
Purpose: assign motors for the motor system
Entry Conditions:
target - the target desired sensor array
one->twenty - ports for desired sensor ports
Exit Conditions: NONE
Global: NONE
Special Note: 21 overloaded functions
***************************************************************************************/
//zero sensors
void assignSensorArray()
{
	//Do nothing
}

//one sensor
void assignSensorArray(sensorArray& target, sensor one)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 1;

	//assign sensors to ports
	target.sensors[0] = one;

	//configure sensors to ports
	configureSensor(target);
}

//two sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 2;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;

	//configure sensors to ports
	configureSensor(target);
}

//three sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 3;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;

	//configure sensors to ports
	configureSensor(target);
}

//four sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 4;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;

	//configure sensors to ports
	configureSensor(target);
}

//five sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 5;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;

	//configure sensors to ports
	configureSensor(target);
}

//six sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 6;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;

	//configure sensors to ports
	configureSensor(target);
}

//seven sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 7;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;

	//configure sensors to ports
	configureSensor(target);
}

//eight sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 8;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;

	//configure sensors to ports
	configureSensor(target);
}

//nine sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 9;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;

	//configure sensors to ports
	configureSensor(target);
}

//ten sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 10;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;

	//configure sensors to ports
	configureSensor(target);
}

//eleven sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 11;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;

	//configure sensors to ports
	configureSensor(target);
}

//twelve sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;

	//configure sensors to ports
	configureSensor(target);
}

//thirteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;

	//configure sensors to ports
	configureSensor(target);
}

//fourteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;

	//configure sensors to ports
	configureSensor(target);
}

//fifteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;

	//configure sensors to ports
	configureSensor(target);
}

//sixteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;
	target.sensors[15] = sixteen;

	//configure sensors to ports
	configureSensor(target);
}

//seventeen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;
	target.sensors[15] = sixteen;
	target.sensors[16] = seventeen;

	//configure sensors to ports
	configureSensor(target);
}

//eighteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;
	target.sensors[15] = sixteen;
	target.sensors[16] = seventeen;
	target.sensors[17] = eighteen;

	//configure sensors to ports
	configureSensor(target);
}

//nineteen sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen, sensor nineteen)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;
	target.sensors[15] = sixteen;
	target.sensors[16] = seventeen;
	target.sensors[17] = eighteen;
	target.sensors[18] = nineteen;

	//configure sensors to ports
	configureSensor(target);
}

//twenty sensors
void assignSensorArray(sensorArray& target, sensor one, sensor two, sensor three, sensor four, sensor five, sensor six, sensor seven, sensor eight, sensor nine, sensor ten,
sensor eleven, sensor twelve, sensor thirteen, sensor fourteen, sensor fifteen, sensor sixteen, sensor seventeen, sensor eighteen, sensor nineteen, sensor twenty)
{
	//reset the sensor system
	resetSensor(target);

	//set total amount of sensors in system
	target.sensorAmt = 12;

	//assign sensors to ports
	target.sensors[0] = one;
	target.sensors[1] = two;
	target.sensors[2] = three;
	target.sensors[3] = four;
	target.sensors[4] = five;
	target.sensors[5] = six;
	target.sensors[6] = seven;
	target.sensors[7] = eight;
	target.sensors[8] = nine;
	target.sensors[9] = ten;
	target.sensors[10] = eleven;
	target.sensors[11] = twelve;
	target.sensors[12] = thirteen;
	target.sensors[13] = fourteen;
	target.sensors[14] = fifteen;
	target.sensors[15] = sixteen;
	target.sensors[16] = seventeen;
	target.sensors[17] = eighteen;
	target.sensors[18] = nineteen;
	target.sensors[19] = twenty;

	//configure sensors to ports
	configureSensor(target);
}

/***************************************************************************************
Function: resetMotorSystem(motorSystem)
Purpose: reset the desired motor system
Entry Conditions: motorSystem& - the motorSystem& to be reset
Exit Conditions: NONE
Global: NONE
Special Note: NONE
***************************************************************************************/
void resetMotorSystem(motorSystem& target)
{
	//set all motors in system to -1
	for(int i = 0; i < (sizeof(target)/2); i++)
		target.motors[i] = -1;

	//set total amount of motors in the system to zero
	target.motorAmt = 0;
}

/***************************************************************************************
Function: assignMotorSystem(motorSystem, int...)
Purpose: assign motors for the motor system
Entry Conditions:
target - the target desired motor system
one->ten - ports for desired motor ports
Exit Conditions: NONE
Global: NONE
Special Note: 11 overloaded functions
***************************************************************************************/
//zero motors
void assignMotorSystem()
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports: NONE");
}

//one motor
void assignMotorSystem(motorSystem& target, int one)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 1;

	//assign motors to ports
	target.motors[0] = one;
}

//two motors
void assignMotorSystem(motorSystem& target, int one, int two)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 2;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
}

//three motors
void assignMotorSystem(motorSystem& target, int one, int two, int three)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 3;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
}

//four motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 4;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
}

//five motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 5;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
}

//six motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");
	motorPortAsString(six);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 6;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
	target.motors[5] = six;
}

//seven motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");
	motorPortAsString(six);
	writeDebugStreamLine(" ");
	motorPortAsString(seven);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 7;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
	target.motors[5] = six;
	target.motors[6] = seven;
}

//eight motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");
	motorPortAsString(six);
	writeDebugStreamLine(" ");
	motorPortAsString(seven);
	writeDebugStreamLine(" ");
	motorPortAsString(eight);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 8;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
	target.motors[5] = six;
	target.motors[6] = seven;
	target.motors[7] = eight;
}

//nine motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");
	motorPortAsString(six);
	writeDebugStreamLine(" ");
	motorPortAsString(seven);
	writeDebugStreamLine(" ");
	motorPortAsString(eight);
	writeDebugStreamLine(" ");
	motorPortAsString(nine);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 9;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
	target.motors[5] = six;
	target.motors[6] = seven;
	target.motors[7] = eight;
	target.motors[8] = nine;
}

//ten motors
void assignMotorSystem(motorSystem& target, int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten)
{
	//debug stream
	writeDebugStreamLine(" ");
	writeDebugStreamLine("Assigning Ports...");
	writeDebugStreamLine("Motor System Ports:");
	motorPortAsString(one);
	writeDebugStreamLine(" ");
	motorPortAsString(two);
	writeDebugStreamLine(" ");
	motorPortAsString(three);
	writeDebugStreamLine(" ");
	motorPortAsString(four);
	writeDebugStreamLine(" ");
	motorPortAsString(five);
	writeDebugStreamLine(" ");
	motorPortAsString(six);
	writeDebugStreamLine(" ");
	motorPortAsString(seven);
	writeDebugStreamLine(" ");
	motorPortAsString(eight);
	writeDebugStreamLine(" ");
	motorPortAsString(nine);
	writeDebugStreamLine(" ");
	motorPortAsString(ten);
	writeDebugStreamLine(" ");

	//reset the motor system
	resetMotorSystem(target);

	//set total amount of motors in system
	target.motorAmt = 10;

	//assign motors to ports
	target.motors[0] = one;
	target.motors[1] = two;
	target.motors[2] = three;
	target.motors[3] = four;
	target.motors[4] = five;
	target.motors[5] = six;
	target.motors[6] = seven;
	target.motors[7] = eight;
	target.motors[8] = nine;
	target.motors[9] = ten;
}

#endif
