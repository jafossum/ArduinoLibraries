/*
 Name:		JAF_EscControllerLib.h
 Created:	12/27/2015 12:25:37 AM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#ifndef _JAF_EscControllerLib_h
#define _JAF_EscControllerLib_h

#include <Servo.h>

class JAF_EscControllerLib
{
private:

	Servo _servo;
	uint8_t _minLimit = 700;
	uint8_t _maxLimit = 2300;

public:

	JAF_EscControllerLib();

	void init(uint8_t pinNumber);
	void arm();
	void writeMicrosec(uint8_t micros);
	void writeRelativeOuput(uint8_t output);
	void setLimits(uint8_t minLimit, uint8_t maxLimit);
};

#endif

