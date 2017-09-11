/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: imolements inout    *
 * of the system						 *
 ****************************************/
#include "Input.h"
#include "Imdb.h"
#include "Output.h"

Input::Input(Imdb* db) {
	this->system = db;

}

void Input::splitCommandLine(char* commandNum, char* commandLine) {

	this->data.clear(); // checking no other strings were before.

	string buffer;
	istringstream ss(commandLine);

	char token;
	if (strcmp(commandNum, JOIN_MOVIES)) {

		token = ' ';
	} else {

		token = ',';
	}

	while (getline(ss, buffer, token)) {
		this->data.push_back(buffer);
	}
}

void Input::streamInput(char* commandNum, char* commandLine) {

	// we keep the input until -1 is typed

	if (!strcmp(commandNum, END_PROGRAM)) {
		return;
	}

	// we make shure we have a parameters line.
	if (commandLine != NULL) {
		splitCommandLine(commandNum, commandLine);
	}

	if (!strcmp(commandNum, GET_NEW_MOVIE)) {
		inputMovie();
		return;
	}

	if (!strcmp(commandNum, GET_NEW_EXPERT)) {
		inputExpert();
		return;
	}

	if (!strcmp(commandNum, ADD_EXPERT_TO_MOVIE)) {
		belongExpertToMovie();
		return;
	}

	if (!strcmp(commandNum, BELONG_MOVIE_TO_GENRE)) {
		belongMovieToGenre();
		return;
	}
	if (!strcmp(commandNum, SORT_EXPERTS_OF_MOVIE)) {
		sortMovie();
		return;
	}
	if (!strcmp(commandNum, PRINT_EXPERTS_OF_MOVIE)) {
		printCrewOfMovie();
		return;
	}
	if (!strcmp(commandNum, PRINT_MOVIE)) {
		printMovie();
		return;
	}
	if (!strcmp(commandNum, JOIN_MOVIES)) {
		joinMovies();
		return;
	}
	if (!strcmp(commandNum, PRINT_EXPERT_MOVIES)) {
		printExpertMovies();
		return;
	}
	if (!strcmp(commandNum, DELETE_MOVIE)) {
		deleteMovie();
		return;
	}

	if (!strcmp(commandNum, DELETE_EXPERT)) {
		deleteExpert();
		return;
	}

	if (!strcmp(commandNum, REMOVE_EXPERT_FROM_MOVIE)) {
		removeExpertFromMovie();
		return;
	}

	if (!strcmp(commandNum, PRINT_ALL_MOVIES)) {
		printAllMovies();
		return;
	}
	if (!strcmp(commandNum, PRINT_ALL_EXPERTS)) {
		printAllExperts();
		return;
	}
	if (!strcmp(commandNum, PRINT_BY_GENRE)) {
		printByGenre();
		return;
	}

	// in case coomand number is not legal
	this->system->out->printActionLegality(false);

}

void Input::inputMovie() {

	// defining variables to be sended to movie as paramaters.

	stringstream ssint, ssdouble;
	string code, name, imageLink;
	int length = 0, year = 0;
	double rank = 0;
	string description;

	/**
	 * extracting from data vector of strings the info,
	 * and entering it to the corresponding variable of the movie,
	 */
	code = this->data[0];
	name = this->data[1];

	ssint.str(this->data[2]);
	ssint >> length;
	ssint.clear();
	ssint.str(this->data[3]);
	ssint >> year;

	ssdouble.str(this->data[4]);
	ssdouble >> rank;

	imageLink = this->data[5];

	for (unsigned int i = 5; i < this->data.size(); i++) {
		description += this->data[i] + " ";
	}

	this->system->addMovie(code, name, length, year, rank, imageLink,
			description);
}

void Input::inputExpert() {

	stringstream ssint, sslong;

	int type = 0;
	;
	long id = 0;
	int age = 0;
	string description, gender, name;

	ssint.str(this->data[0]);
	ssint >> type;
	ssint.clear();

	sslong.str(this->data[1]);
	sslong >> id;

	ssint.str(this->data[2]);
	ssint >> age;

	description = this->data[3];

	gender = this->data[4];

	for (unsigned int i = 5; i < this->data.size(); i++) {
		name += this->data[i] + " ";
	}

	this->system->addExpert(type, id, age, description, gender, name);

}

void Input::belongExpertToMovie() {

	stringstream ss;
	string code;
	long id = 0;

	code = this->data[0];
	ss.str(this->data[1]);
	ss >> id;

	this->system->belongExpertToMovie(code, id);

}

void Input::belongMovieToGenre() {

	string code = this->data[0], name = this->data[1];
	this->system->belongMovieToGenre(code, name);

}

void Input::sortMovie() {

	stringstream ss;
	string movieCode;
	int sortMethod = 0;

	movieCode = this->data[0];
	ss.str(this->data[1]);
	ss >> sortMethod;

	this->system->sortMovie(movieCode, sortMethod);

}

void Input::printCrewOfMovie() {

	string code = this->data[0];

	this->system->printMovieCrew(code);
}

void Input::printMovie() {

	string code = this->data[0];

	this->system->printSingleMovie(code);
}

void Input::joinMovies() {
	this->system->joinMovies(this->data);
}

void Input::printExpertMovies() {

	stringstream ss;
	long id = 0;
	ss.str(this->data[0]);

	ss >> id;

	this->system->printMoviesByExpert(id);

}

void Input::deleteMovie() {
	string code = this->data[0];

	this->system->removeMovie(code);
}

void Input::deleteExpert() {
	stringstream ss;
	long id = 0;

	ss.str(this->data[0]);
	ss >> id;

	this->system->removeExpert(id);

}

void Input::removeExpertFromMovie() {
	stringstream ss;

	string code = this->data[0];
	long id = 0;
	;
	ss.str(this->data[1]);
	ss >> id;

	this->system->removeExpertFromMovie(code, id);
}

void Input::printAllMovies() {
	this->system->printAllMovies();
}

void Input::printAllExperts() {
	this->system->printAllExperts();
}

void Input::printByGenre() {

	string name = this->data[0];

	this->system->printMoviesByGenre(name);
}
