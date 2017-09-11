/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * writer behaviour					 *
 ****************************************/
#include "Writer.h"

Writer::Writer(long id, int age, string descript, string gender, string name) :
				Expert(id, age, descript, gender, name) {

	// constructor.
}

string Writer::toString() {

	return this->name + " " + this->description + "\n";


}




