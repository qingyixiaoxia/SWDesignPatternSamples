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

#ifndef DESIGN_PATTERN_ADAPTER_H
#define DESIGN_PATTERN_ADAPTER_H
#ifdef WIN32
#include <windows.h>
#endif

typedef void (*Func_Loop)(void *pUser);

class IThreadWrapper
{
public:
	virtual ~IThreadWrapper() {}
	virtual bool create(Func_Loop pLoopFunc) = 0;
	virtual bool start() = 0;
	virtual bool join() = 0;
};

#ifdef WIN32
class WinThreadImpl : public IThreadWrapper
{
private:
	typedef HANDLE Thread_Handle;
	typedef DWORD  Thread_ID;

public:
	~WinThreadImpl();
	bool create(Func_Loop pLoopFunc);
	bool start();
	bool join();

private:
	static DWORD WINAPI win_loop(LPVOID pUser);

private:
	Thread_Handle m_threadHandle;
	Thread_ID  m_threadId;
	Func_Loop m_loopFunc;
};
#endif

#ifdef LINUX
class LinuxThreadImpl : public IThreadWrapper
{
private:
	typedef pthread_t Thread_Handle;
	
public:
	~LinuxThreadImpl();
	bool create(Func_Loop pLoopFunc);
	bool start();
	bool join();

private:
	static void* linux_loop(void* pUser);

private:
	Thread_Handle m_threadHandle;
	Func_Loop m_loopFunc;
};
#endif

class client_threadwrapper
{
public:
	client_threadwrapper();
	~client_threadwrapper();

	void runTest();

private:
	static void onLoop(void *pUser);

private:
	IThreadWrapper* m_pThreadHandler;
};

#endif