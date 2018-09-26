#include "http.h"
#include <cstdlib>
#include <iostream>

HTTP::HTTP(const string& _server, int _port){
	server = _server;
	port = _port;
	
	queue_lock = false;
	requests = new queue<HTTPRequest*>;

	connection_status = "";
	last_error = "";

//	current_file = "";
//	current_size = 0;
//	current_downloaded = 0;

	connected = false;
	current_download = NULL;
	
	buffer = (char*)malloc(PAGE_SIZE);
	
	// Start WSOCK.DLL
	if((WSAStartup(MAKEWORD(2, 2), &wsaData))==SOCKET_ERROR){
		connection_status = "Could not open socket";
	}
	
	running = true;
	
	fout.open("HTTP.log", ios::out | ios::app);
	fout << "Started\n";
}

HTTP::~HTTP(){	

	WSACleanup();

	delete [] buffer;
	while(!requests->empty()){
		HTTPRequest* httpr = requests->front();
		requests->pop();
		delete httpr;
	}
	delete requests;
	
	fout << "Closed\n\n";
	fout.close();
}

void	HTTP::printError(){
	int i = WSAGetLastError();
/*
	if(i==WSAEINTR)fout << "Interrupted function call.\n";
	if(i==WSAEACCES)fout << "Permission denied.\n";
	if(i==WSAEFAULT)fout << "Bad address.\n";
	if(i==WSAEINVAL)fout << "Invalid argument.\n";
	if(i==WSAEMFILE)fout << "Too many open files.\n";
	if(i==WSAEWOULDBLOCK)fout << "Resource temporarily unavailable.\n";
	if(i==WSAEINPROGRESS)fout << "Operation now in progress.\n";
	if(i==WSAEALREADY)fout << "Operation already in progress.\n";
	if(i==WSAENOTSOCK)fout << "Socket operation on nonsocket.\n";
	if(i==WSAEDESTADDRREQ)fout << "Destination address required.\n";
	if(i==WSAEMSGSIZE)fout << "Message too long.\n";
	if(i==WSAEPROTOTYPE)fout << "Protocol wrong type for socket.\n";
	if(i==WSAENOPROTOOPT)fout << "Bad protocol option.\n";
	if(i==WSAEPROTONOSUPPORT)fout << "Protocol not supported.\n";
	if(i==WSAESOCKTNOSUPPORT)fout << "Socket type not supported.\n";
	if(i==WSAEOPNOTSUPP)fout << "Operation not supported.\n";
	if(i==WSAEPFNOSUPPORT)fout << "Protocol family not supported.\n";
	if(i==WSAEAFNOSUPPORT)fout << "Address family not supported by protocol family.\n";
	if(i==WSAEADDRINUSE)fout << "Address already in use.\n";
	if(i==WSAEADDRNOTAVAIL)fout << "Cannot assign requested address.\n";
	if(i==WSAENETDOWN)fout << "Network is down.\n";
	if(i==WSAENETUNREACH)fout << "Network is unreachable.\n";
	if(i==WSAENETRESET)fout << "Network dropped connection on reset.\n";
	if(i==WSAECONNABORTED)fout << "Software caused connection abort.\n";
	if(i==WSAECONNRESET)fout << "Connection reset by peer.\n";
	if(i==WSAENOBUFS)fout << "No buffer space available.\n";
	if(i==WSAEISCONN)fout << "Socket is already connected.\n";
	if(i==WSAENOTCONN)fout << "Socket is not connected.\n";
	if(i==WSAESHUTDOWN)fout << "Cannot send after socket shutdown.\n";
	if(i==WSAETIMEDOUT)fout << "Connection timed out.\n";
	if(i==WSAECONNREFUSED)fout << "Connection refused.\n";
	if(i==WSAEHOSTDOWN)fout << "Host is down.\n";
	if(i==WSAEHOSTUNREACH)fout << "No route to host.\n";
	if(i==WSAEPROCLIM)fout << "Too many processes.\n";
	if(i==WSASYSNOTREADY)fout << "Network subsystem is unavailable.\n";
	if(i==WSAVERNOTSUPPORTED)fout << "Winsock.dll version out of range.\n";
	if(i==WSANOTINITIALISED)fout << "Successful WSAStartup not yet performed.\n";
	if(i==WSAEDISCON)fout << "Graceful shutdown in progress.\n";
	if(i==WSATYPE_NOT_FOUND)fout << "Class type not found.\n";
	if(i==WSAHOST_NOT_FOUND)fout << "Host not found.\n";
	if(i==WSATRY_AGAIN)fout << "Nonauthoritative host not found.\n";
	if(i==WSANO_RECOVERY)fout << "This is a nonrecoverable error.\n";
	if(i==WSANO_DATA)fout << "Valid name, no data record of requested type.\n";
	if(i==WSA_INVALID_HANDLE)fout << "Specified event object handle is invalid.\n";
	if(i==WSA_INVALID_PARAMETER)fout << "One or more parameters are invalid.\n";
	if(i==WSA_IO_INCOMPLETE)fout << "Overlapped I/O event object not in signaled state.\n";
	if(i==WSA_IO_PENDING)fout << "Overlapped operations will complete later.\n";
	if(i==WSA_NOT_ENOUGH_MEMORY)fout << "Insufficient memory available.\n";
	if(i==WSA_OPERATION_ABORTED)fout << "Overlapped operation aborted.\n";
//	if(i==WSAINVALIDPROCTABLE)fout << "Invalid procedure table from service provider.\n";
//	if(i==WSAINVALIDPROVIDER)fout << "Invalid service provider version number.\n";
//	if(i==WSAPROVIDERFAILEDINIT)fout << "Unable to initialize a service provider.\n";
	if(i==WSASYSCALLFAILURE)fout << "System call failure.\n";
*/
}

void	HTTP::connect(const string& host, int port){
	if(connected)return;	

	connection_status = "Trying to connect to "+server;
//	fout << "Connection: " << connection_status << "\n";
//	fout.flush();
	
	// create my socket
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// make sure nothing bad happened
	if(sock==SOCKET_ERROR){
		connection_status = "Socket error";
		fout << "Connection: " << connection_status << "\n";
		fout.flush();
		return;
	}

	struct hostent* host_entry;

	// setup the host entry
	if ((host_entry = gethostbyname(host.data())) == NULL){
		connection_status = "Unknown host";
		fout << "Connection: " << connection_status << "\n";
		fout.flush();
		return;
	}
	
	struct sockaddr_in server;

	// fill in the server socket info
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = *(unsigned long*) host_entry->h_addr;

	// connect to the server
	const char* hostbuf = host.c_str();

	sockaddr_in clientService; 
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr( host.data() );
	clientService.sin_port = htons( port );

	if (::connect( sock, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR) {
		connection_status = "Unable to connect";
		fout << "Connection: " << connection_status << " (" << host << ") \n";
		fout.flush();
		return;
	}
	
	// Yay!
	connection_status = "Connected to "+host;
//	fout << "Connection: " << connection_status << "\n";
//	fout.flush();
	
	connected = true;	
}

void	HTTP::disconnect(){
	if(connected){
		connection_status = "Closing connection";
//		fout << "Connection: " << connection_status << "\n";
//		fout.flush();

		closesocket(sock);

		connected = false;		
		connection_status = "Connection closed";
//		fout << "Connection: " << connection_status << "\n";
//		fout.flush();
		
	}
}

void	HTTP::download(HTTPRequest* request){
	current_download = request;
	
	// Initialize settings
	current_download->downloaded = 0;
	current_download->duration = 0;
	current_download->size = 0;
	current_download->locked = true;
	current_download->finished = false;
	current_download->result = 0;

	if(!connected){
		current_download->locked = false;
		current_download->result = -1;
		last_error = "No connection";
		fout << "Error: " << last_error << "\n";
		fout.flush();
		return;
	}

	
	int n = timeGetTime();
	
		
	// Create our own strings so we can modify
	string localfile = request->local_file;
	string remotefile = request->remote_file;
	
	// Replace ? to ! (cant save files with ? in em)
	int t = localfile.find("?", 0);
	while(t!=string::npos){
		localfile.replace(t, 1, "!");
		t = localfile.find("?", 0);
	}
	
	// server.urlencode
	t = remotefile.find(" ", 0);
	while(t!=string::npos){
		remotefile.erase(t, 1);
		remotefile.insert(t, "%20");
		t = remotefile.find(" ", 0);
	}

	// Construct GET message
	send_msg = "GET /"+ remotefile +" HTTP/1.1\r\nHost: "+ server +"\r\n";
	send_msg += "Connection: Close\r\n\r\n";
	

	// Send Get:	
	if(::send(sock, send_msg.data(), send_msg.length(), 0) == SOCKET_ERROR){
		last_error = "Could not send request";
		fout << "Error: " << last_error << "\n";
		fout.flush();
		request->locked = false;
		request->result = -1;
		return;
	}

	// Grab first incoming message (includes the header)
	int nBytes = recv(sock, buffer, PAGE_SIZE, 0);
	
	// Put buffer in the message
	recv_msg = buffer;
	
	// Find header size
	int header_size = recv_msg.find("\r\n\r\n");
	if(header_size==string::npos){
		last_error = "Header too large or incorrect response";
		fout << "Error: " << last_error << "\n";
		fout.flush();
		request->locked = false;
		request->result = -1;
		return;
	}
	
	// Create a string with only the header in it
	header = recv_msg.substr(0, header_size);							// dont include \r\n\r\n
	
	// Keep the remaining bytes
//	recv_msg = recv_msg.substr(header_size+4, recv_msg.size()-header_size-5);		// 4 = \r\n\r\n

	// Process each header line
	int		next_eol = header.find("\n");
	int		line = 0;
	int		colon = 0;
	
	// Loop through header lines
	while(next_eol!=string::npos){
		header_line = header.substr(0, next_eol-1);
		
		if(line==0){
			// The first header line is the response code
			if(header_line.find("200 OK")==string::npos){
				last_error = header_line.substr(9, header_line.size()-9);
				fout << "Error: File: [" << remotefile << "] yields [" << last_error << "]\n";
				fout.flush();
				request->locked = false;
				request->result = -1;
				return;		
			}
		} else {
			// Other headers, split in property:value
			colon = header_line.find(":");
			if(colon==string::npos){
				last_error = "Invalid header ("+ header_line +")";
				fout << "Error: " << last_error << "\n";
				fout.flush();
				request->locked = false;
				request->result = -1;
				return;
			} else {
				header_property = header_line.substr(0, colon);
				header_value = header_line.substr(colon+2, header_line.size()-colon-2);
				
				// Do stuff with the header
				if(header_property=="Content-Length"){
					current_download->size = atoi(header_value.data());
				}
				
			}
		}

		// Cut off the header line from our receive buffer, and try to find the next header line
		header = header.substr(next_eol+1, header.size()-next_eol-1);
		next_eol = header.find("\n");
		line++;
	}
	
	// Header OK, now the rest of the recv buffer is data for our file

	// Create file C style
	FILE* file = fopen(localfile.data(), "wb");

	if(!file){
		last_error = "Unable to write to "+localfile;
		fout << "Error: " << last_error << "\n";
		fout.flush();
				
		request->locked = false;
		request->result = -1;
		return;
	}
	
	
	// Dump the rest of the receive buffer into the file
	fwrite(buffer+header_size+4, sizeof(char), nBytes-header_size-4, file);
	current_download->downloaded += nBytes-header_size-4;
	if(current_download->downloaded>current_download->size)current_download->size=current_download->downloaded;
	
	// Grab the rest of the file and add it to the file
	while(nBytes != 0){
		nBytes = recv(sock, buffer, PAGE_SIZE, 0);
		if(nBytes!=0){
			fwrite(buffer, sizeof(char), nBytes, file);
			current_download->downloaded += nBytes;
			if(current_download->downloaded>current_download->size)current_download->size=current_download->downloaded;
		}
	}

	// Close file
	fclose(file);
		
	current_download->duration = timeGetTime() - n;
//	current_download->size = current_downloaded;
	current_download->locked = false;
	current_download->finished = true;

}

void	HTTP::run(){
	while(running){
	
		// While there is no connection
		/*
		while(!connected){

			// Wait a while
			Sleep(2);
			
			// Try to reconnect
		}
		*/
		// Loop until the queue is empty or disconnected
		while(requests->empty())Sleep(1);

		while(!requests->empty()){
			connect(server, port);
			HTTPRequest* request = requests->front();
			while(queue_lock);
			queue_lock = true;				
			requests->pop();
			queue_lock = false;				
			download(request);
			disconnect();
		}
	}
}

void	HTTP::addRequest(HTTPRequest* _request){
	while(queue_lock);
	queue_lock = true;
	requests->push(_request);
	queue_lock = false;
}
