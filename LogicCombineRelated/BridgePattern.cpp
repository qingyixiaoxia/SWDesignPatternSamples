/* Copyright Wenjing Li. and other Node contributors. All rights reserved.
* Author: Wenjing Li, GitHub Address: http://www.github.com/qingyixiaoxia
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "BridgePattern.h"

hahaTemperature::~hahaTemperature()
{
}

float hahaTemperature::getTemperature()
{
	return 38.11;
}

heheTemperature::~heheTemperature()
{
}
float heheTemperature::getTemperature()
{
	return 35.22;
}

bool TemperatureAlarm::isAlarming(TemperatureDevice *pDevice)
{
	float temp = pDevice->getTemperature();
	if (isTooHigh(temp) || isTooLow(temp))
	{
		return true;
	}

	return false;
}

TempAlarmStrategy001::~TempAlarmStrategy001()
{
}

bool TempAlarmStrategy001::isTooHigh(float temp)
{
	if (temp > 40)
	{
		return true;
	}

	return false;
}

bool TempAlarmStrategy001::isTooLow(float temp)
{
	if (temp < 30)
	{
		return true;
	}

	return false;
}

TempAlarmStrategy002::~TempAlarmStrategy002()
{
}

bool TempAlarmStrategy002::isTooHigh(float temp)
{
	if (temp > 38)
	{
		return true;
	}

	return false;
}

bool TempAlarmStrategy002::isTooLow(float temp)
{
	if (temp < 36)
	{
		return true;
	}

	return false;
}