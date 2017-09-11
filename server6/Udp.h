/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#ifndef UDP_H_
#define UDP_H_

#include "Connection.h"


/**
 * defines behaviour of UDP object class.
 * only close is implemented in this class.
 * all other functions are implemented above ( ClientTcp, ServerTcp)
 */
class Udp: public Connection {


protected:

	struct sockaddr_in from; // information of socket data came from

public:

	Udp(int portNum);

	virtual ~Udp();

	virtual void Initialize();

	void dataReceive(char* buffer, int size);

	virtual void dataSend(char* data);


	void terminate();

};

#endif /* UDP_H_ */
