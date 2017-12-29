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

#include "ProxyPattern.h"

RemoteServerProxy::~RemoteServerProxy()
{
	m_listenerVec.clear();
}

bool RemoteServerProxy::connect(std::string serverIP)
{
	/* Call Interface of Remote server to setup connection */
	// TODO
	// TODO
	return true;
}

bool RemoteServerProxy::sendData(const char* pDataBuf, unsigned int dataLen)
{
	/* Call Interface of Remote Server to send out the data to server */
	// TODO 
	// TODO
	return true;
}

bool RemoteServerProxy::registerDataListener(IListener *pDataListener)
{
	if (pDataListener == false)
	{
		return false;
	}

	for (int i = 0; i < m_listenerVec.size(); i++)
	{
		if (m_listenerVec.at(i) == pDataListener)
		{
			return true;  // Already register the same listener yet !
		}
	}

	m_listenerVec.push_back(pDataListener);
	return true;
}

Client_proxy::Client_proxy()
{
	m_server = new RemoteServerProxy();
}

Client_proxy::~Client_proxy()
{
	if (m_server != NULL)
	{
		delete m_server;
	}
}

void Client_proxy::runTest()
{
	char pData[] = "Hello, world!";

	m_server->registerDataListener(this);
	m_server->connect("127.0.0.1");
	m_server->sendData(pData, sizeof(pData));
}

void Client_proxy::onReceiveData(const char* pDataBuf, unsigned int dataLen)
{
	printf("On receiving data, buffer = %s, length = %d \n", pDataBuf, dataLen);
}