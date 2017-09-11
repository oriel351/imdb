/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:            *
 ****************************************/

#ifndef SERVERFILES_SERVER_H_
#define SERVERFILES_SERVER_H_

#define SIZE_OF_BUFFER 4096

#include <pthread.h>

class Connection;
class Imdb;
class ThreadManager;

/**
 * this structure contains all information neede for each new connection:
 * conn - the Tcp connection info.
 * clientSocket - of the client - whrer to response.
 * system - the image database.
 */
struct connData {

	Connection* conn;
	int clientSocket;
	Imdb* system;

};

/**
 * this class defines all behaviours and manages server operations
 */
class Server {

private:

	Connection* conn;

public:

	/**
	 * constructor.
	 * initializing lock mutex as well.
	 * @param type of connection- 0 - UDP, 1 - TCP.
	 * @param portNum the port used for communication.
	 */
	Server(int type, int portNum);

	/**
	 * start the server, waiting for clients.
	 * this fucntions stops to untill accepted connection
	 */
	void Start();

	virtual ~Server();

};

#endif /* SERVERFILES_SERVER_H_ */
