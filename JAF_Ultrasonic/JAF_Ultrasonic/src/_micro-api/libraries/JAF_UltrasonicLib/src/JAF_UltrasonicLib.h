/*
 Name:		JAF_UltrasonicLib.h
 Created:	1/19/2016 8:06:39 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#ifndef _JAF_UltrasonicLib_h
#define _JAF_UltrasonicLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define INTERUPTPIN 3
#define TRIGGERPIN 2
#define DISTANCE_CALC 0.017

typedef enum MEASSURE_STATE
{
	IDLE=0,
	TRIGGER=1,
	WAITING=2,
	MEASSURE=3,
}MEASSURE_STATE;

class JAF_UltrasonicLib
{

private:
	void _startMeassurement(void);
	uint8_t _trigPin;
	uint32_t _startTime;
	uint16_t _timerId;
	uint16_t _lastDistance;
	MEASSURE_STATE _state;

public:
	JAF_UltrasonicLib(void);
	void init();
	void calculateMeassurement();
	uint16_t getMeassurement(void);
	
};

#endif

