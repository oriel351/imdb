/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#ifndef SERVERFILES_SERVERTCP_H_
#define SERVERFILES_SERVERTCP_H_

#include "Tcp.h"
#include <pthread.h>

class ServerTcp: public Tcp {

protected:
	int clientSock;
	struct sockaddr_in from; // information of socket data came from

public:

	ServerTcp(int portNum);

	virtual ~ServerTcp();

	virtual void initialize();

	int acceptCon();

	virtual void dataReceive(char* buffer, int size);

	virtual void dataSend(char* data);

	// in order to maintain backwardds compability we only overload receive and send functions in serverTCP :
	// we do not want to change behaviour for future clients or servers using old methods:

	virtual void dataReceive(char* buffer, int size, int clientSock);

	virtual void dataSend(char* data, int clientSock);

};

#endif /* SERVERFILES_SERVERTCP_H_ */
