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

#ifndef DESIGN_PATTERN_PROXY_H
#define DESIGN_PATTERN_PROXY_H
#include <string>
#include <vector>

class IListener
{
public:
	virtual void onReceiveData(const char* pDataBuf, unsigned int dataLen) = 0;
};

class IServer
{
public:
	virtual ~IServer() {}
	virtual bool connect(std::string serverIP) = 0;
	virtual bool sendData(const char* pDataBuf, unsigned int dataLen) = 0;
	virtual bool registerDataListener(IListener *pDataListener) = 0;
};

class RemoteServerProxy : public IServer 
{
public:
	RemoteServerProxy() {}
	~RemoteServerProxy();
	bool connect(std::string serverIP);
	bool sendData(const char* pDataBuf, unsigned int dataLen);
	bool registerDataListener(IListener *pDataListener);

private:
	std::vector<const IListener*> m_listenerVec;
};

class Client_proxy : public IListener
{
public:
	Client_proxy();
	~Client_proxy();
	void runTest();

private:
	void onReceiveData(const char* pDataBuf, unsigned int dataLen);

private:
	IServer* m_server;
};
#endif