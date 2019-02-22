#pragma once

#include<WinSock2.h>
#include<WS2tcpip.h>
#include<string>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "5000"
#define BUFFER_LENGTH 512

using namespace std;

class Client {
	private: 
		const char* serverAddress;
		const char* port;

		SOCKET connectSocket = INVALID_SOCKET;
		WSADATA wsaData;
		int status;
		struct addrinfo *result = NULL,
			*ptr = NULL,
			hints;

		int recvBufferLength = BUFFER_LENGTH;
		char recvbuf[BUFFER_LENGTH];

	public:
		Client() {};
		void initSock();
		void setupAddr();
		void checkAddr();
		void connectClient();
		void setup(const char* addr = "127.0.0.1");
		bool sendMsg(const char* str);
		string recieveMsg();
		void flushInput();

};

