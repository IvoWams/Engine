using namespace std;

#ifndef HTTPTHREAD_H
#define HTTPTHREAD_H

#include "http.h"
#include <string>

class HTTPThread{
	private:
		static DWORD WINAPI run(PVOID);
		
	public:
		HTTPThread(const string&, int);
		~HTTPThread();

		HTTP* http;
};

#endif
