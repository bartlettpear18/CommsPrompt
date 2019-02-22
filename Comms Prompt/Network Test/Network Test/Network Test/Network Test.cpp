#include "pch.h"
#include <iostream>
#include <thread>
#include"Client.h"

#include<WinSock2.h>
#include<WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "5000"

using namespace std;

Client client;
string input;
string ipAddr;

void sender();
void reader();

int main() {

	//Setup connection
	cout << "Enter IP Address of Phone: ";
	cin >> ipAddr;
	client.setup(ipAddr.c_str());

	thread output(sender);
	thread input(reader);

	output.join();
	input.join();
	   	
	return 0;	
}

void sender() {
	while (true) {
		getline(cin, input);
		client.sendMsg(input.c_str());
		input = "";

	}
}

void reader() {
	while (true) {
		cout << client.recieveMsg() << endl;;
		client.flushInput();
	}
}
