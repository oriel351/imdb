/*
 * Tcp.h
 *
 *  Created on: Dec 22, 2015
 *      Author: kati
 */

#ifndef INCLUDE_TCP_H_
#define INCLUDE_TCP_H_
#include "Connection.h"

/**
 * defines behaviour of tcp object class.
 * only close is implemented in this class.
 * all other functions are implemented above ( ClientTcp, ServerTcp)
 */
class Tcp: public Connection {

public:

	Tcp(int portNum);

	virtual ~Tcp();

	virtual void Initialize();

	virtual void dataReceive(char* buffer, int size);

	virtual void dataSend(char* data);


	void terminate();

};


#endif /* INCLUDE_TCP_H_ */
