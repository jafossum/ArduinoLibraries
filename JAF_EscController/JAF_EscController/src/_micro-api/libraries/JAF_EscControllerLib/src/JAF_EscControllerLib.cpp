/*
 Name:		JAF_EscControllerLib.cpp
 Created:	12/27/2015 12:25:37 AM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include <Arduino.h>
#include "JAF_EscControllerLib.h"

#define DEBUG 1

JAF_EscControllerLib::JAF_EscControllerLib(){}

#pragma region Members

/* Setting Servo PIN Number and saturation limits on the ESC Output.

(micros)minLimit = 0% output
(micros)maxLimit = 100% output */

void JAF_EscControllerLib::init(uint8_t pinNumber, uint16_t minLimit, uint16_t maxLimit)
{
	_minLimit = minLimit;
	_maxLimit = maxLimit;

	this->attach((int)pinNumber, minLimit, maxLimit);
}

// Arm the ESC. Sets signal so low the ESC can be armed
void JAF_EscControllerLib::arm()
{
	// Write PWN to uotput pin
	this->writeMicroseconds(1000);

	// Arming device. No output will be written before this flag is set.
	_armed = true;
}

// Set output to ESC 0 - 100%
void JAF_EscControllerLib::writeMicrosec(uint16_t micros)
{
//#if DEBUG
	Serial.print("Input micros on servo: ");
	Serial.println(micros);
//#endif

	if (_armed)
	{
		// Write PWN to uotput pin
		this->writeMicroseconds((int)constrain(micros, _minLimit, _maxLimit));

//#if DEBUG
		Serial.print("OutPut micros: ");
		Serial.println(constrain(micros, _minLimit, _maxLimit));
//#endif
	}
	else
	{
//#if DEBUG
		Serial.print("OutPut NOT POSSIBLE. DEVICE NOT ARMED");
//#endif
	}
	
}

// Set output to ESC 0 - 100%
void JAF_EscControllerLib::writeRelativeOuput(uint8_t output)
{
//#if DEBUG
	Serial.print("Procentage output: ");
	Serial.println(output);
//#endif

	// Constrain output between 0 and 100%
	output = constrain(output, 0, 100);

//#if DEBUG
	Serial.print("Actual OutPut: ");
	Serial.println(output);
//#endif

	if (_armed) {
		// Write PWN to uotput pin
		this->writeMicroseconds((int)map(output, 0, 100, _minLimit, _maxLimit));
	}
	else {
//#if DEBUG
		Serial.print("OutPut NOT POSSIBLE. DEVICE NOT ARMED");
//#endif
	}

}

#pragma endregion

