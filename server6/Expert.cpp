/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * Expert behaviour*					 *
 ****************************************/

#include "Expert.h"
#include "Movie.h"


Expert::Expert(long id, int age, string descript, string gender, string name) {
	this->age = age;
	this->gender = gender;
	this->id = id;
	this->description = descript;
	this->name = name;

	// constructor.
}

Expert::~Expert() {
	// Destructor.
}

long Expert::getId() const {
	return this->id;
}

int Expert::getAge() const {
	return this->age;
}

string Expert::getDescription() {
	return this->description;
}

string Expert::getGender() {
	return this->gender;
}

string Expert::getName() {
	return this->name;
}

vector<Movie*> Expert::getMovies() const {
	return this->movies;
}

bool Expert::addMovie(Movie* movie) {

	// validating does not exist already
	if (getMovie(movie->getCode()) == NULL) {
		this->movies.push_back(movie);
		return true;
	}
	// if exists already, isn't added , returns false;
	return false;

}

void Expert::printMovies() {
	for (unsigned int i = 0; i < this->movies.size(); i++) {
		// this->movies->at(i)->toString();
	}

}

string Expert::toString() {
	return "expert";
}

Movie* Expert::getMovie(string code) {

	Movie* mov = NULL;
	for (unsigned int i = 0; i < this->movies.size(); i++) {
		// we look for the movie by its code.
		if (this->movies.at(i)->getCode().compare(code) == 0) {
			mov = this->movies.at(i);
			break;
		}
	}
	return mov;
}

bool Expert::removeMovie(Movie* movie) {

	vector<Movie*>::iterator position = find(this->movies.begin(),
			this->movies.end(), movie);

	if (position != this->movies.end()) { // ==  mov->getCrew()[i]->getMovies().end() means the element was not found
		this->movies.erase(position);
		return true;
	} else {
		return false;
	}

}
