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

#include "AdapterPattern.h"
#include <thread>

#ifdef WIN32
/*
CreateThread(
　LPSECURITY_ATTRIBUTES lpThreadAttributes, 
　SIZE_T dwStackSize, 
　LPTHREAD_START_ROUTINE lpStartAddress, 
　LPVOID lpParameter, 
　DWORD dwCreationFlags, 
　LPDWORD lpThreadId 
);
*/

WinThreadImpl::~WinThreadImpl()
{
	DWORD dwExitCode;
	BOOL result = TerminateThread(m_threadHandle, dwExitCode);
}

bool WinThreadImpl::create(Func_Loop pLoopFunc)
{
	m_threadHandle = CreateThread(0, 0, win_loop, this, 0, &m_threadId);

	return true;
}

bool WinThreadImpl::start()
{
	return true;
}

bool WinThreadImpl::join()
{
	WaitForSingleObject(m_threadHandle, 0);
	return true;
}

DWORD WINAPI WinThreadImpl::win_loop(LPVOID pUser)
{
	WinThreadImpl* pThis = (WinThreadImpl*)pUser;
	if (pThis == NULL)
	{
		return 0;
	}

	if (pThis->m_loopFunc != NULL)
	{
		pThis->m_loopFunc((void*)pThis);
	}

	return 0;
}
#endif

#ifdef LINUX
LinuxThreadImpl::~WinThreadImpl()
{
	// TODO 
	// TODO
}

bool LinuxThreadImpl::create(Func_Loop pLoopFunc)
{
	// TODO 
	// TODO
	return true;
}

bool LinuxThreadImpl::start()
{
	// TODO 
	// TODO
	return true;
}

bool LinuxThreadImpl::join()
{
	// TODO 
	// TODO
	return true;
}

void* LinuxThreadImpl::linux_loop(void* pUser)
{
	// TODO 
	// TODO
}
#endif

client_threadwrapper::client_threadwrapper()
{
	m_pThreadHandler = new WinThreadImpl();
}

client_threadwrapper::~client_threadwrapper()
{
	if (m_pThreadHandler != NULL)
	{
		delete m_pThreadHandler;
	}
}

void client_threadwrapper::runTest()
{
	m_pThreadHandler->create((Func_Loop)onLoop);
	m_pThreadHandler->start();
	m_pThreadHandler->join();
}

void client_threadwrapper::onLoop(void *pUser)
{
	printf("Hello, world!\n");
}