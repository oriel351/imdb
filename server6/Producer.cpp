/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * producer behaviour*					 *
 ****************************************/

#include "Producer.h"

Producer::Producer(long id, int age, string descript, string gender, string name) :
				Expert(id, age, descript, gender, name) {

	// constructor.
}

string Producer::toString() {

	return this->name + "\n";
}

