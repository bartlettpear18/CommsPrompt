#include "pch.h"
#include "Client.h"
#include<iostream>

using namespace std;

void Client::initSock(){
	status = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (status != 0) {
		cout << "WSAStartup failed: " << status << endl;
	}
	cout << "WSAStartup succesful" << endl;
}

void Client::setupAddr(){
	//Setup server address
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	status = getaddrinfo(serverAddress, PORT, &hints, &result);
	if (status != 0) {
		cout << "getaddrinfo failed: " << status;
		WSACleanup();
	}
	
	cout << "Ready for address" << endl;

}

void Client::checkAddr(){
	ptr = result;
	connectSocket = socket((*ptr).ai_family, (*ptr).ai_socktype, (*ptr).ai_protocol);

	if (connectSocket == INVALID_SOCKET) {
		cout << "Error at socket: " << WSAGetLastError();
		freeaddrinfo(result);
		WSACleanup();
	}

	cout << "Address checked" << endl;

}

void Client::connectClient() {
	status = connect(Client::connectSocket, (*ptr).ai_addr, (int)(*ptr).ai_addrlen);
	if (status != 0) {
		closesocket(connectSocket);
		connectSocket = INVALID_SOCKET;
	}

	freeaddrinfo(result);
	if (connectSocket == INVALID_SOCKET) {
		cout << "Unable to connect to server";
		WSACleanup();
	}

	cout << "Connected" << endl;
}

void Client::setup(const char* addr) {

	Client::serverAddress = addr;
	cout << "Begin connection" << endl;
	initSock();
	setupAddr();
	checkAddr();
	connectClient();
}

bool Client::sendMsg(const char* str) {
	Client::status = send(Client::connectSocket, str, (int)strlen(str), 0);
	if (status == SOCKET_ERROR) {
		cout << "Send failed: " << WSAGetLastError();
		closesocket(connectSocket);
		WSACleanup();
		return false;
	}
	return true;
}

string Client::recieveMsg() {
	status = recv(connectSocket, recvbuf, recvBufferLength, 0);
	if (status > 0) {
		return recvbuf;
	} else if (status == 0) {
		cout << "Connection closed" << endl;
	} else {
		cout << "Recieve failed: " << WSAGetLastError() << endl;
	}
	return NULL;
}

void Client::flushInput()
{
	recvbuf[0] = 0;
}
