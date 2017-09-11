/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#include "ServerUdp.h"

ServerUdp::ServerUdp(int portNum) :
		Udp(portNum) {

}

ServerUdp::~ServerUdp() {
	// TODO Auto-generated destructor stub
}

void ServerUdp::initialize() {

	this->sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("error creating socket");
	}

	// struct sockaddr_in sin;
	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->portNumber);

	// bind part :

	if (bind(this->sock, (struct sockaddr *) &this->sin, sizeof(this->sin))
			< 0) {
		perror("error binding to socket");
	}

}

void ServerUdp::dataSend(char* data) {

	int data_len = strlen(data);

	int sent_bytes = sendto(this->sock, data, data_len, 0,
			(struct sockaddr *) &this->from, sizeof(this->from));
	if (sent_bytes < 0) {
		perror("error writing to socket");
	}

}
