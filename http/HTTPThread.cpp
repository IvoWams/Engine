#include "HTTPThread.h"

HTTPThread::HTTPThread(const string& server, int port){
	http = new HTTP(server, port);
	
    DWORD dwThreadId = 0;
    HANDLE hThread = NULL;
    
	hThread = CreateThread(
              NULL,                  		// Default thread security descriptor
              1024,                     	// Default stack size
              HTTPThread::run,			  	// Start routine
              this,                 		// Start routine parameter
              0,                     		// Run immediately
              &dwThreadId		            // Thread ID
              );
}

HTTPThread::~HTTPThread(){
	// ...
}

DWORD	HTTPThread::run(PVOID p){
	HTTPThread* m = (HTTPThread*)p;
	m->http->run();
}
