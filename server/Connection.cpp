/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#include "Connection.h"

Connection::Connection(int portNum) {
	this->portNumber = portNum;
	this->sock = -1;

}

Connection::~Connection() {
}

void Connection::initialize() {
}

void Connection::dataReceive(char* buffer, int size) {
}

void Connection::dataSend(char* data) {
}

void Connection::terminate() {
}
