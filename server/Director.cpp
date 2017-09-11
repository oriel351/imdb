/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * director behaviour*					 *
 ****************************************/

#include "Director.h"

Director::Director(long id, int age, string descript, string gender, string name) :
				Expert(id, age, descript, gender, name) {
}

string Director::toString() {

	return this->name + "\n";
}
