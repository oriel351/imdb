/*
 * ServerTcp.cpp
 *
 *  Created on: Dec 21, 2015
 *      Author: kati
 */

#include "ServerTcp.h"
#include "Server.h"

ServerTcp::ServerTcp(int portNum) :
		Tcp(portNum) {
	this->clientSock = -1;

}

ServerTcp::~ServerTcp() {
	// TODO Auto-generated destructor stub
}

void ServerTcp::initialize() {
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("error creating socket");
	}

	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->portNumber);

	if (bind(this->sock, (struct sockaddr *) &this->sin, sizeof(this->sin))
			< 0) {
		perror("error binding socket");
	}

	if (listen(this->sock, 5) < 0) {
		perror("error listening to a socket");
	}

}

int ServerTcp::acceptCon() {

	// reseting this->from for the new connection with new client
	memset(&this->from, 0, sizeof(this->from));
	unsigned int addr_len = sizeof(this->from);

	this->clientSock = accept(this->sock, (struct sockaddr *) &this->from,
			&addr_len);

	if (this->clientSock < 0) {
		perror("error accepting client");
	}
	return this->clientSock;
}

void ServerTcp::dataReceive(char* buffer, int size) {

	int expected_data_len = size;
	int read_bytes = recv(this->clientSock, buffer, expected_data_len, 0);
	if (read_bytes == 0) {
		// connection is closed
	} else if (read_bytes < 0) {
		perror("error reading from socket");
	}

}

void ServerTcp::dataSend(char* data) {

	int data_len = strlen(data);
	int sent_bytes = send(this->clientSock, data, data_len, 0);

	if (sent_bytes < 0) {
		// error
	}

}

//  ******************8FROM HERE IS THE EXTENSIONFO MULTI THREADING **************** :

void ServerTcp::dataReceive(char* buffer, int size, int clientSocket) {

	int expected_data_len = size;
	int read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
	if (read_bytes == 0) {
		// connection is closed
	} else if (read_bytes < 0) {
		perror("error reading from socket");
	}

}

void ServerTcp::dataSend(char* data, int clientSocket) {

	int data_len = strlen(data);
	int sent_bytes = send(clientSocket, data, data_len, 0);

	if (sent_bytes < 0) {
		// error
	}
}
