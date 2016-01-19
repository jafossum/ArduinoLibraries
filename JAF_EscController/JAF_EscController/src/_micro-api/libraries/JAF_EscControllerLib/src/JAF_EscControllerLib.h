/*
 Name:		JAF_EscControllerLib.h
 Created:	12/27/2015 12:25:37 AM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#ifndef _JAF_EscControllerLib_h
#define _JAF_EscControllerLib_h

#include <Servo.h>

class JAF_EscControllerLib : Servo
{
private:

	uint16_t _minLimit;
	uint16_t _maxLimit;

public:

	JAF_EscControllerLib();

	void init(uint8_t pinNumber);
	void arm();
	void writeMicrosec(uint16_t Micros);
	void writeRelativeOuput(uint8_t output);
	void setLimits(uint16_t minLimit, uint16_t maxLimit);

	int readSetting();
	int readSettingMicroseconds();
};

#endif

