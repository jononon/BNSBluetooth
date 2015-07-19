#pragma config(UART_Usage, UART1, uartUserControl, baudRate38400, IOPins, None, None)
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

task main()
{
	// The way to reprogram a HC05 bluetooth module is through AT commands.  Typicall you
	// need to have an arduino or usb->uart converter to reprogram the module, but this file
	// allows you to reprogram them via the Vex Cortex.
	// To send these commands, you need to set the module into an AT mode.  This is done by
	// set the "key" pin to high (5V), which can be supplied by the cortex UART/I2C ports, or
	// sensor ports.
	writeDebugStreamLine("Team BNS HC05 AT Commands Demo!");
	writeDebugStreamLine("Note: Ensure the 'Key' pin is connected to a 3.3V source (or 5V) and powercycle the HC05!");
	writeDebugStreamLine("    : You will know you're in AT mode when the light blinks at ~2sec intervals.\n");

	// Whenever you are in AT mode on an HC05, the default baudrate is 38400!
	setBaudRate(UART1, baudRate38400);

	// Execute several AT commands if we detect an HC05 module connected.
	if (bnsATTestConnection(UART1))
	{
		bnsATGetVersion(UART1);
		bnsATGetName(UART1);
		bnsATSetBaudrate(UART1, 57600, 1, 0);
		bnsATGetBaudrate(UART1);

		bnsATSetName(UART1, "TEAM BNS");
	}

	writeDebugStreamLine("Done!");
	while(1==1){;}
}
