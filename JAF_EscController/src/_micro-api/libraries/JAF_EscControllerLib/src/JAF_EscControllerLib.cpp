/*
 Name:		JAF_EscControllerLib.cpp
 Created:	12/27/2015 12:25:37 AM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include <Arduino.h>
#include "JAF_EscControllerLib.h"

JAF_EscControllerLib::JAF_EscControllerLib(){}

#pragma region Members

void JAF_EscControllerLib::init(uint8_t pinNumber)
{
	_servo.attach((int)pinNumber);
}

/* Setting saturation limits on the ESC Output. Set lowLimit higher than
arming value of ESC to avoid arming when not intended

(micros)minLimit = 0% output
(micros)maxLimit = 100% output */
void JAF_EscControllerLib::setLimits(uint8_t minLimit, uint8_t maxLimit)
{
	if (minLimit > maxLimit){
		_minLimit = minLimit;
		_maxLimit = maxLimit;

	}
	else{
		Serial.println("ERROR WHEN SETTING LIMITS!");
	}

}

// Arm the ESC. Sets signal so low the ESC can be armed
void JAF_EscControllerLib::arm()
{
	// NOT IMPLEMENTED YET
}

// Set output to ESC 0 - 100%
void JAF_EscControllerLib::writeMicrosec(uint8_t micros)
{
//#if DEBUG
	Serial.print("Input micros on servo: ");
	Serial.println(micros);
	Serial.print("Upper limit: ");
	Serial.println(_maxLimit);
	Serial.print("Lower limit: ");
	Serial.println(_minLimit);
//#endif

	// Constrain between Min and Max value
	micros = constrain(micros, _minLimit, _maxLimit);

//#if DEBUG
	Serial.print("OutPut micros: ");
	Serial.println(micros);
//#endif

	// Write PWN to uotput pin
	_servo.writeMicroseconds((int)micros);
}

// Set output to ESC 0 - 100%
void JAF_EscControllerLib::writeRelativeOuput(uint8_t output)
{
//#if DEBUG
	Serial.print("Procentage output: ");
	Serial.println(output);
//#endif

	// Set value no lower than lower limit
	if ((output < 0) || (output > 1000)){
		output = 0;
	}

	// Set value no higher than upper limit
	if (output > _maxLimit){
		output = 100;
	}

//#if DEBUG
	Serial.print("Actual OutPut: ");
	Serial.println(output);
//#endif

	// Write PWN to uotput pin
	_servo.writeMicroseconds((int)map(output, 0, 100, _minLimit, _maxLimit));
}

#pragma endregion

