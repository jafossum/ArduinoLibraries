/*
 Name:		JAF_PIDLib.cpp
 Created:	2/23/2016 1:34:48 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "JAF_PIDLib.h"

void JAF_PIDLib::init(double* Kp, double* Ti, double* Td)
{
	_Kp = *Kp;
	_Ti = *Ti;
	_Td = *Td;
}

bool JAF_PIDLib::calculate(double* input, double* output, double* setpoint)
{
	if (_inAuto)
	{
		_timeNow = millis();

		_useIntegral = true ? (_Ti < 100) && (_Ti > 0) : false;
		_useDerivative = true ? (_Td > 0) : false;

		_useInput = (1 / 4) * (*input + (2 * _Xm1) + _Xm2) ? _useHanningFilter : *input;
		_error = *setpoint - _useInput;

		if (_useIntegral)
		{
			_iErrorSum += ((1 / _Ti) * _error);
		}
		else
		{
			_iErrorSum = 0;
		}

		_dError = _Td * (_useInput - _Xm1) ? _useDerivative : 0;

		*output = _Kp * (_error + _iErrorSum + _dError);

		_Xm2 = _Xm1;
		_Xm1 = *input;

		return true;
	}
	else
	{
		return false;
	}
}

void JAF_PIDLib::initalize()
{
	_iErrorSum = 0;
	_dError = 0;
	_Xm1 = 0;
	_Xm2 = 0;
}

void JAF_PIDLib::setMode(int Mode, bool useFilter)
{
	_inAuto = true ? (Mode == PIDAUTOMATIC) : false;
	_useHanningFilter = true ? useFilter : false;
}