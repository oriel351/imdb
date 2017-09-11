/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#ifndef SERVERUDP_H_
#define SERVERUDP_H_


#include "Udp.h"

class ServerUdp: public Udp {

public:


	ServerUdp(int portNum);

	virtual void initialize();

	virtual void dataSend(char* data);

	virtual ~ServerUdp();

};

#endif /* SERVERUDP_H_ */
