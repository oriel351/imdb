/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * genre			 *
 ****************************************/
#include "Genre.h"
#include "Movie.h"

Genre::Genre(string name) {
	this->name = name;
}
Genre::~Genre() {

}
bool Genre::addMovie(Movie* movie) {

	// validating does not exist already
	if (getMovie(movie->getCode()) == NULL) {
		this->movies.push_back(movie);
		return true;
	}
	// if exists already, isn't added , returns false;
	return false;

}

void Genre::removeMovie(Movie* movie) {
	vector<Movie*>::iterator position = find(this->movies.begin(),
			this->movies.end(), movie);

	if (position != this->movies.end()) {// ==  mov->getCrew()[i]->getMovies().end() means the element was not found
		this->movies.erase(position);

	}
}

vector<Movie*> Genre::getMovies() {
	return this->movies;
}
string Genre::getName() {
	return this->name;
}

Movie* Genre::getMovie(string code) {

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
