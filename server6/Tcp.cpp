/*
 * Tcp.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: kati
 */

#include "Tcp.h"

Tcp::Tcp(int portNum) :
		Connection(portNum) {
}

Tcp::~Tcp() {
}

void Tcp::Initialize() {
}

void Tcp::dataSend(char* data) {}

void Tcp::dataReceive(char* buffer, int size) {}
void Tcp::terminate() {
	close(this->sock);

}
