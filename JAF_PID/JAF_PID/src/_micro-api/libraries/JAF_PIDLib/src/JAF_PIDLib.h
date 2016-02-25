/*
 Name:		JAF_PIDLib.h
 Created:	2/23/2016 1:34:48 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#ifndef _JAF_PIDLib_h
#define _JAF_PIDLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define PIDAUTOMATIC 1

class JAF_PIDLib
{
public:
	JAF_PIDLib();
	~JAF_PIDLib();

	void init(double* Kp, double* Ti, double* Td);
	bool calculate(double* input, double* output, double* setpoint);
	void setMode(int Mode, bool useFilter);
	void initalize();

private:
	bool _inAuto;
	bool _useIntegral;
	bool _useDerivative;
	bool _useHanningFilter;

	double _Kp;
	double _Ti;
	double _Td;

	double _iErrorSum;
	double _dError;
	double _Xm1, _Xm2;
	double _useInput;
	double _error;

	double _lastTime;
	double _timeNow;
};

JAF_PIDLib::JAF_PIDLib()
{
}

JAF_PIDLib::~JAF_PIDLib()
{
}

#endif

