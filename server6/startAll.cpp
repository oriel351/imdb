/*********************************************
 * Student Name: Oriel Gaash, ID : 302462825 *
 * Student Name: Kati Adler, ID: 312730336   *
 * Exercise Name: assignment 4               *
 * File description:  the main function      *
 *********************************************/

#include "Server.h"
#include <stdlib.h>
/*********************************************************************
 *  Program does: starts a new Server and waits for commands         *
 *  start Image Database system (Imdb)                               *
 * The operation: creates an object of Imdb nad runs everything      *
 * through start() function.                                         *
 *********************************************************************/

int main(int argv,char *argc[]) {

	 Server* prog = new Server(atoi(argc[1]), atoi(argc[2]));

	 prog->Start();
	 delete prog;
	 return 0;
}

