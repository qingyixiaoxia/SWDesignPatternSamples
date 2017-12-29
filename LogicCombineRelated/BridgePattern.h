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

#ifndef DESIGN_PATTERN_BRIDGE_H
#define DESIGN_PATTERN_BRIDGE_H

class TemperatureDevice
{
public:
	virtual ~TemperatureDevice(){}
	virtual float getTemperature() = 0;
};

class hahaTemperature : public TemperatureDevice
{
public:
	~hahaTemperature();
	float getTemperature();
};

class heheTemperature : public TemperatureDevice
{
public:
	~heheTemperature();
	float getTemperature();
};

/************** TemperatureAlarm class act as a bridge ****************/
class TemperatureAlarm   
{
public:
	virtual ~TemperatureAlarm() {}
	bool isAlarming(TemperatureDevice *pDevice);

public:
	virtual bool isTooHigh(float temp) = 0;
	virtual bool isTooLow(float temp) = 0;
};

class TempAlarmStrategy001 : public TemperatureAlarm
{
public:
	~TempAlarmStrategy001();
	bool isTooHigh(float temp);
	bool isTooLow(float temp);
};

class TempAlarmStrategy002 : public TemperatureAlarm
{
public:
	~TempAlarmStrategy002();
	bool isTooHigh(float temp);
	bool isTooLow(float temp);
};

#endif