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

#if defined(__AVR_ATmega2560__)
#define INTERUPTPIN 19
#define TRIGGERPIN 18
#else
#define INTERUPTPIN 3
#define TRIGGERPIN 2
#endif

#define DISTANCE_CALC_CM 58

class JAF_UltrasonicLib
{

private:
	
	uint8_t _maxDist;
	uint16_t _range;
	volatile unsigned long _startTime, _endTime;
	volatile bool _finished;
	
	static void _signal();
	static JAF_UltrasonicLib* _instance;

public:
	JAF_UltrasonicLib(int max_dist);

	void init();
	void trigg(void);
	uint16_t getRange(void);

	bool isFinished(){ return _finished; }
	static JAF_UltrasonicLib* instance(){ return _instance; }
};

#endif

