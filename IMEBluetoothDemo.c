#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  IME1,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// ------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// The author can be contacted by email at jmarple@umass.edu
//
// ------------------------------------------------------------------------
#include "BNSlib_HC05.h"

// This task continuously transmits sensor data.
task transmitSensorData
{
	while(1==1)
	{
		// Convert the IME value
		string imeStr;
		stringFormat(imeStr, "%f\r\n", SensorValue[IME1]);

		// Send Data
		bnsSerialSend(UART1, "IME1:");
		bnsSerialSend(UART1, (char*)&imeStr);

		delay(1000);
	}
}

task main()
{
	writeDebugStreamLine("Team BNS HC05 Bluetooth Demo!");
	writeDebugStreamLine("Note: Ensure the 'Key' pin is disconnected and power has been cycled!");
	writeDebugStreamLine("    : You will know you're in the right mode when the light flashes quickly.  When a device is connected, it will blink twice in a row, every so often");
	writeDebugStreamLine("    : Also, ensure the baudrate set in the program matches what is programmed into the HC05!");

	// This should match what the AT command set the baudrate to!
	setBaudRate(UART1, baudRate57600);

	startTask(transmitSensorData);

	while(1==1){;}
}
