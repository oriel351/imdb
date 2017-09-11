/****************************************
 * Student Name: Oriel Gaash  * 
 * Exercise Name: assignment 5           *
 * File description:                     *
 ****************************************/

#include "Server.h"

#include "ServerUdp.h"
#include "ServerTcp.h"

#include "Imdb.h"

Server::Server(int type, int portNum) {

	if (pthread_mutex_init(&lock, NULL) != 0) {
		cout << " coud not instiate lock" << endl;
	}

	if (type == 0) { // UDP case
		this->conn = new ServerUdp(portNum);
	} else {
		this->conn = new ServerTcp(portNum);
	}

}

/**
 * this function manages each single thread, and responds with all clients requirements from the movie database.
 * @param ptr, which contains a structure which contains the connection data, and socket number.
 *
 */
static void* runSingleThread(void* ptr) {

	// retrieving data from void* which hold a struct with client info.
	connData* cd = (connData*) ptr;

	ServerTcp* conn;
	conn = (ServerTcp*) (cd->conn);
	int clientSocket = cd->clientSocket;

	Imdb* system = cd->system;

	delete cd;

	char commandNumber[128];

	string s = "start on!";

	strcpy(commandNumber, s.c_str());

	cout << "oriel" << endl;
	char buffer[SIZE_OF_BUFFER]; // to store info of the next command.
	char commandLine[SIZE_OF_BUFFER * 2];

	while (strcmp(commandNumber, "-1")) {

		// reseting buffers for iteration:

		memset(&buffer[0], 0, sizeof(buffer));
		memset(&commandNumber[0], 0, sizeof(commandNumber));
		memset(&commandLine[0], 0, sizeof(commandLine));

		//  WAITING FOR COMMAND FROM CLIENT :

		cout << "almost receive" << endl;

		conn->dataReceive(buffer, sizeof(buffer), clientSocket);

		cout << "received: " << endl;

		cout << buffer << endl;
		//  parsingn command into line and number :

		char numBuf[128];
		strncpy(numBuf, buffer, 5);
		// numBuf[5] = '\0';
		char* strok = strtok(numBuf, " \n");

		strcpy(commandNumber, strok);

		char* copyFrom = strchr(buffer, ' '); // pointer to begining of all the rest of line, i.e the command.

		if (copyFrom != NULL) {
			strncpy(commandLine, copyFrom + 1, sizeof(buffer));
		}

		// PROCCESSING DATA IN IMDB :

		system->pushCommand(commandNumber, commandLine);
		string response = system->getOutput();

		// SENDING RESPONSE BACK TO CLIENT :

		cout << "almost send" << endl;
		memset(&buffer[0], 0, sizeof(buffer));
		strcpy(buffer, response.c_str()); // getting info from string to buffer char sequence.

		if (strcmp(commandNumber, "-1")) {
			conn->dataSend(buffer, clientSocket); // sends data to client
		}

	}

	return NULL;
}

void Server::Start() {

	/*
	 * only initializes connection, only one time needed to happen
	 * accept happens in threadManager
	 */
	conn->initialize();

	pthread_t t1;

	// accepting connections as long as  manually server will be shut down.
	while (true) {

		int currentClientSocket = ((ServerTcp*) this->conn)->acceptCon();

		Imdb* system = Imdb::getInstance();

		connData* data = new connData;

		data->clientSocket = currentClientSocket;
		data->conn = this->conn;
		data->system = system;

		// creating the new thread for the new client.

		int status = pthread_create(&t1, NULL, runSingleThread, (void*) data);
		if (status) {
			cout << "error opening new thread" << endl;
		}

	}

	// TERMINATION COMMAND TO SERVER - close socket

	this->conn->terminate();

}

Server::~Server() {

	delete this->conn;
	pthread_mutex_destroy(&lock);
}

