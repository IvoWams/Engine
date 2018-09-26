using namespace std;

#ifndef HTTP_H
#define HTTP_H

#include <queue>
#include <string>
#include <stdio.h>
#include <winsock2.h>
#include <fstream>

// Provides a serial queueing device for components via HTTP
// And an interface to provide feedback to the client
// Note: each http object is connected to a single server


// Amount of bytes during downloaded during each loop
#define PAGE_SIZE 4096

typedef struct {

	string	remote_file;	// set, file on the server including subdirs
	string	local_file;		// set, the file to be created on the client including subdirs
	int		downloaded;		// unset, updated when downloading
	int		size;			// unset, the size of the file, Content-Size : ####, if no such HTTP header, 0 until finished
	int		duration;		// unset, the time it took to download
	bool	locked;			// unset, flagged when being processed
	bool	finished;		// unset, flagged when the file is complete
	int		result;			// unset, -1 if an error occurs
	
} HTTPRequest;

class HTTP {
	private:		
		// The pipe
		bool					queue_lock;
		queue<HTTPRequest*>*	requests;
				
		// Functionality to grab files through HTTP
		void					download(HTTPRequest*);
		
		// Download buffer
		char*					buffer;
		
		// TCP connection build and destroy
		// Todo: Keep-Alive
		bool					connected;
		void					connect(const string&, int);
		void					disconnect();
		
		// Server variables
		string					server;
		int						port;
		int						sock;
		
		// Reports WSA GetLastError
		void					printError();
		
		// WSA data
		WSAData					wsaData;
		
		// Reuseable strings
		string					send_msg;
		string					recv_msg;
//		string					recv_header;

		string					header;
		string					header_line;
		string					header_property;
		string					header_value;

//		string					recv_header_line;

		fstream					fout;
		
	public:
		HTTP(const string&, int);
		~HTTP();
		
		bool					isConnected(){ return connected; }
		
		// Connectection Info and Last Error
		string					connection_status;
		string					last_error;
		
		// Current downloading
		HTTPRequest*			current_download;

		// Interface		
		void					addRequest(HTTPRequest*);
		
		// Set to false to stop loop
		bool					running;
		
		// Called by thread
		void					run();
};

#endif
