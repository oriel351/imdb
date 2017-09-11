/***********************************************
 * Students Names: Oriel Gaash  Kati Adler      *
 * Exercise Name: assignment 4                  *
 * File description:   abstract connection      *
 ************************************************/

#ifndef INCLUDE_CONNECTION_H_
#define INCLUDE_CONNECTION_H_

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;


/**
 * this class defines a behaviour of connection by network objects.
 * this is pure virtual, so all methods are derived and implemented above.
 * is used as interface.
 */
class Connection {

protected:

	int sock;
	struct sockaddr_in sin;
	int portNumber;

public:
	/**
	 * Constructor.
	 */
	Connection(int portNum);

	/**
	 * destructor( default)
	 */
	virtual ~Connection();

	/**
	 * initializes the connection, including bind, connect, and
	 * and accept where neccesssary.
	 */
	virtual void initialize();

	/**
	 * receives data in current connection object (Client/server)
	 */
	virtual void dataReceive(char* buffer, int size);

	/**
	 * sends data in current connection object (Client/server)
	 * 
	 */
	virtual void dataSend(char* data);

	/**
	 * terminates current connection, closes the socket.
	 */
	virtual void terminate();

};

#endif /* INCLUDE_CONNECTION_H_ */
