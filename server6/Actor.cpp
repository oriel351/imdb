/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements actor
 * behaviour. *
 ****************************************/



Actor::Actor(long id, int age, string descript, string gender, string name) :
		Expert(id, age, descript, gender, name) {

	// constructor.
}

string Actor::toString() {

	string actor = this->name;
	stringstream ss;
	ss << this->age;
	actor += " " + ss.str() + "\n";
	return actor;

}


