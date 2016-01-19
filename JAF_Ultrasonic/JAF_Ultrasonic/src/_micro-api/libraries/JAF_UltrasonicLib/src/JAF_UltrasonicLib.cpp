/*
 Name:		JAF_UltrasonicLib.cpp
 Created:	1/19/2016 8:06:39 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "JAF_UltrasonicLib.h"

JAF_UltrasonicLib::JAF_UltrasonicLib()
{

}

void JAF_UltrasonicLib::init()
{
	_state = IDLE;
}

uint16_t JAF_UltrasonicLib::getMeassurement()
{
	if (_state == IDLE)
	{
		this->_startMeassurement();
	}

	return _lastDistance;
}

void JAF_UltrasonicLib::calculateMeassurement()
{
	_state = MEASSURE;
	_lastDistance = (micros() - _startTime) * DISTANCE_CALC;
	_state = IDLE;
}

void JAF_UltrasonicLib::_startMeassurement()
{
	_state = TRIGGER;

	// Set trigPin high
	PORTD |= B00001000;

	delayMicroseconds(10);

	// Set trigpin Low
	PORTD &= B11110111;

	// getTime
	_startTime = micros();
	_state = WAITING;
}


