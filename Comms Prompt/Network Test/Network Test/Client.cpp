#include<pch.h>
#include<iostream>
#include<winw>
#include<Winsock2.h>
#include<WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "5000"

using namespace std;

class Client {
	private:
		WSAData wsaData;
};


cout << "Input Server Address: ";
char serverAddress[] = "000.000.000.000";
cin >> serverAddress;

WSADATA wsaData;
int status;

struct addrinfo *result = NULL,
	*ptr = NULL,
	hints;

SOCKET connectSocket = INVALID_SOCKET;

//Init winsock
status = WSAStartup(MAKEWORD(2, 2), &wsaData);
if (status != 0) {
	cout << "WSAStartup failed: " << status << endl;
	return 1;
}

//Setup server address
ZeroMemory(&hints, sizeof(hints));
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_protocol = IPPROTO_TCP;

status = getaddrinfo(serverAddress, PORT, &hints, &result);
if (status != 0) {
	cout << "getaddrinfo failed: " << status;
	WSACleanup();
	return 1;
}

//Check server address
ptr = result;
connectSocket = socket((*ptr).ai_family, (*ptr).ai_socktype, (*ptr).ai_protocol);

if (connectSocket == INVALID_SOCKET) {
	cout << "Error at socket: " << WSAGetLastError();
	freeaddrinfo(result);
	WSACleanup();
	return 1;
}

//Connect to server
status = connect(connectSocket, (*ptr).ai_addr, (int)(*ptr).ai_addrlen);
if (status != 0) {
	closesocket(connectSocket);
	connectSocket = INVALID_SOCKET;
}

freeaddrinfo(result);
if (connectSocket == INVALID_SOCKET) {
	cout << "Unable to connect to server";
	WSACleanup();
	return 1;
}


return 0;