/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#include "Udp.h"

Udp::Udp(int portNum) :
		Connection(portNum) {

}

Udp::~Udp() {

}


void Udp::Initialize() {
}


void Udp::dataReceive(char* buffer, int size) {

	unsigned int from_len =  sizeof(struct sockaddr_in);

	int bytes = recvfrom(this->sock, buffer, size, 0,
			(struct sockaddr *) &this->from, &from_len);

	if (bytes < 0) {
		perror("error reading from socket");
	}
}

void Udp::dataSend(char* data) {
}

void Udp::terminate() {

	close(this->sock);

}
