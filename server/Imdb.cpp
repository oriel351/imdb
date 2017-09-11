/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: implements 		 *
 * all system functions					 *
 ****************************************/

#include "Imdb.h"

#include "Input.h"
#include "Output.h"
#include "Movie.h"
#include "Genre.h"
#include "Actor.h"
#include "Writer.h"
#include "Producer.h"
#include "Director.h"

Imdb* Imdb::getInstance() {

	static bool booleanVar = false;
	static Imdb* instance = NULL;

	if (!booleanVar)

	{

		pthread_mutex_lock(&lock);

		if (!booleanVar) {

			instance = new Imdb();
			booleanVar = true;

		}
		pthread_mutex_unlock(&lock);

	}

	return instance;
}

Imdb::Imdb() {

	this->out = new Output();
	this->in = new Input(this);
}

Imdb::~Imdb() {
	delete this->out;
	delete this->in;

	for (unsigned int i = 0; i < this->experts.size(); i++) {
		delete this->experts[i];
	}

	for (unsigned int i = 0; i < this->movies.size(); i++) {
		delete this->movies[i];
	}

	for (unsigned int i = 0; i < this->genres.size(); i++) {
		delete this->genres[i];
	}
}

void Imdb::pushCommand(char* commandNum, char* commandLine) {

	this->in->streamInput(commandNum, commandLine);

}

void Imdb::addMovie(string code, string name, int length, int year, double rank,
		string imageLink, string descript) {

	// this variable will be returned to let know action
	// completed succesfully. will be sent to output section.

	bool legality = false;
	// validating input legality
	if (getMovie(code) == NULL && length >= 0 && rank >= 0.0 && rank <= 10.0
			&& year >= 1000) {
		this->movies.push_back(
				new Movie(code, name, length, year, rank, imageLink, descript));
		legality = true;
	}
	this->out->printActionLegality(legality);

}

Movie* Imdb::getMovie(string code) {

	Movie* mov = NULL;
	for (unsigned int i = 0; i < this->movies.size(); i++) {
		// we look for the movie by its code.
		if (this->movies.at(i)->getCode() == code) {
			mov = this->movies.at(i);
			break;
		}
	}
	return mov;
}

void Imdb::removeMovie(string code) {

	bool legality = false;
	Movie* mov = getMovie(code);

	// deletting pointer from crew :
	if (mov != NULL) {
		for (unsigned int i = 0; i < mov->getCrew().size(); i++) {

			mov->getCrew()[i]->removeMovie(mov);
		}

		// deleting pointer from genres.

		for (unsigned int i = 0; i < mov->getGenres().size(); i++) {
			mov->getGenres()[i]->removeMovie(mov);

		}

		// removing the movie from imdb database :

		vector<Movie*>::iterator position = find(this->movies.begin(),
				this->movies.end(), mov);

		if (position != this->movies.end()) {// ==  mov->getCrew()[i]->getMovies().end() means the element was not found
			this->movies.erase(position);
		}

		// deleting objecting and freeing memory.
		delete mov;
		legality = true;
	} // END IF  mov!= NULL

	this->out->printActionLegality(legality);
}

void Imdb::belongExpertToMovie(string movieCode, long id) {

	bool legality = false;
	Movie* mov = getMovie(movieCode);
	/**
	 * make it efficient - if movie does not exist, dont waste time on else,
	 * for example searching for the expert.
	 */
	if (mov == NULL) {
		this->out->printActionLegality(legality);
		return;
	}
	Expert* exp = getExpert(id);
	if (exp == NULL) {
		this->out->printActionLegality(legality);
		return;
	}

	// NOW VALIDATING EXPERT WAS NOT ADDED ALREADY TO MOVIE.
	legality = mov->addMember(exp);
	/**
	 *  if and only if movie responded positively to add expert,
	 *  we add movie in expert class. and we validate in cclass expert as well
	 *  (maybe some how has been added alreay to this expert.
	 */
	if (legality) {
		legality = exp->addMovie(mov);
	}

	this->out->printActionLegality(legality);
}

void Imdb::removeExpert(long expertId) {

	bool legality = false;
	Expert* exp = getExpert(expertId);

	// deletting pointer from movies :

	if (exp != NULL) {

		for (unsigned int i = 0; i < exp->getMovies().size(); i++) {

			vector<Movie*>::iterator position = find(this->movies.begin(),
					this->movies.end(), exp->getMovies()[i]);

			if (position != this->movies.end()) { // ==  mov->getCrew()[i]->getMovies().end() means the element was not found
				this->movies[i]->removeMember(exp);
			}

		}
		// removing the expert from imdb database :

		vector<Expert*>::iterator position = find(this->experts.begin(),
				this->experts.end(), exp);

		if (position != this->experts.end()) { // ==  mov->getCrew()[i]->getMovies().end() means the element was not found
			this->experts.erase(position);
		}

		// deleting objecting and freeing memory.
		delete exp;
		legality = true;
	} // END IF  mov!= NULL

	this->out->printActionLegality(legality);

}

void Imdb::removeExpertFromMovie(string movieCode, long expertId) {

	// validating both exist, otherwise, failed operation.

	bool legality = false;

	Movie* mov = getMovie(movieCode);

	// deletting pointer from movies :
	if (mov != NULL) {
		Expert* exp = mov->getExpert(expertId);

		if (exp != NULL) {
			legality = mov->removeMember(exp);
			if (legality) {
				legality = exp->removeMovie(mov);
			}
		}
	} // END IF
	this->out->printActionLegality(legality);

}

void Imdb::addExpert(int type, long id, int age, string description,
		string gender, string name) {

// this variable will be returned to let know action
// completed succesfully. will be sent to output section.

	bool legality = false; // default.
// validating input legality

	if (getExpert(id) == NULL && age >= 0 && type >= 0 && type <= 3) {
		legality = true;

		// CASE 0 - DIRECTOR :

		if (type == DIRECTOR) {
			this->experts.push_back(
					new Director(id, age, description, gender, name));
		}

		// CASE 1 - ACTOR

		if (type == ACTOR) {
			this->experts.push_back(
					new Actor(id, age, description, gender, name));
		}
		// CASE 2 - WRITER

		if (type == WRITER) {
			this->experts.push_back(
					new Writer(id, age, description, gender, name));
		}
		// CASE 3 - PRODUECR

		if (type == PRODUCER) {
			this->experts.push_back(
					new Producer(id, age, description, gender, name));
		}

	}
	this->out->printActionLegality(legality);
}
Expert* Imdb::getExpert(long id) {

	Expert* exp = NULL;
	for (unsigned int i = 0; i < this->experts.size(); i++) {

		// if we find a code identical already in db
		if (this->experts.at(i)->getId() == id) {
			exp = this->experts.at(i);
			break;
		}
	}
	return exp;
}

void Imdb::belongMovieToGenre(string movieCode, string name) {

	bool legality = false;
	Movie* mov = getMovie(movieCode);
	/**
	 * make it efficient - if movie does not exist, dont waste time on else,
	 */
	if (mov == NULL) {
		this->out->printActionLegality(legality);
		return;
	}

	Genre* genre = getGenre(name);

	if (genre == NULL) {
		addGenre(name); // adding genre to database.
		genre = getGenre(name);
	}

	// NOW VALIDATING GENRE (IF EXISTED) WAS NOT ADDED ALREADY TO MOVIE.
	legality = mov->belongGenre(genre);
	/**
	 *  if and only if movie responded positively to add genre,
	 *  we add movie in genre class.
	 */
	if (legality) {
		legality = genre->addMovie(mov);
	}
	this->out->printActionLegality(legality);
}

void Imdb::sortMovie(string movieCode, int sortParam) {

	bool legality = false;

	// first check input is legal:
	Movie* mov = getMovie(movieCode);
	if (sortParam >= 1 && sortParam <= 3 && mov != NULL) {
		mov->setSortingMethod(sortParam);
		mov->sortNow();
		legality = true;
	}
	this->out->printActionLegality(legality);
}

void Imdb::joinMovies(vector<string> codes) {

	/**
	 * the idea is to run only once on the list of code.
	 * we keep mov pointer for curent movie, max pointer for longest,
	 * and an integer first, to know that we had already  a movie pointer
	 * to compare, and at the first time we assign max to the first movie.
	 */

	bool legality = false;

	// validating input movies codes.
	Movie* mov = NULL;
	vector<Movie*> toJoinList; // we store temporally pointers vector..

	for (unsigned int i = 0; i < codes.size(); i++) {
		mov = getMovie(codes[i]);

		if (mov == NULL) {
			this->out->printActionLegality(legality);
			return;

		} else { // i.e  mov is a valid pointer to movie.
			toJoinList.push_back(mov);
		}
	} // END OF FOR

	mov = join(toJoinList, 0, toJoinList.size() - 1);

	// validating this joined movie wasnt addded already:
	if (getMovie(mov->getCode()) == NULL) {
		this->movies.push_back(mov);

		// belonging all experts and genres :

		for (unsigned int i = 0; i < mov->getCrew().size(); i++) {
			mov->getCrew()[i]->addMovie(mov);
		}

		for (unsigned int i = 0; i < mov->getGenres().size(); i++) {
			mov->getGenres()[i]->addMovie(mov);
		}

		legality = true;
	} else {
		delete mov;
	}
	this->out->printActionLegality(legality);

}

Movie* Imdb::join(vector<Movie*> movies, int begin, int end) {

// stopping condition:

// in case we have one movie in smallest vector.
	if (end - begin == 0) {

		Movie* mo = new Movie(movies.at(begin), movies.at(begin)->getCrew(),
				movies.at(begin)->getGenres(), movies.at(begin)->getCode());
		return mo;
	}
// in case we have two movies in smallest vector.
	if (end - begin == 1) {

		return movies[begin]->joinMovies(movies[end]);
	}

	Movie* movLeft = join(movies, 0, end / 2);

	Movie* movRight = join(movies, (end / 2) + 1, end);

	Movie* merge = movLeft->joinMovies(movRight);

	delete movLeft;
	delete movRight;

	return merge;

}

void Imdb::printMoviesByExpert(long expertId) {

	bool legality = false;

	Expert* exp = getExpert(expertId);

	if (exp == NULL) {
		this->out->printActionLegality(legality);
		return;
	}

	string movies;
	for (unsigned int i = 0; i < exp->getMovies().size(); i++) {
		movies += exp->getMovies()[i]->toString();
	}

	if (exp->getMovies().size() != 0) {
		this->out->printSomething(movies);
	} else {
		this->out->printSomething("\n");
	}


}

void Imdb::printMoviesByGenre(string genreName) {

// no need to check nothing. if there are movies - will print.
// else - does nothing
	Genre* gen = getGenre(genreName);
	string movies;
	if (gen != NULL) {
		for (unsigned int i = 0; i < gen->getMovies().size(); i++) {
			movies += gen->getMovies()[i]->toString();
		}

		// just make shure - if no movies in genre - get down one line.
		if (gen->getMovies().size() != 0) {
			this->out->printSomething(movies);
		} else {
			this->out->printSomething("\n");
		}
	} else {
		this->out->printActionLegality(false);
	}

}

void Imdb::printAllMovies() {

// no need to check nothing. if there are movies - will print.
// else - does nothing

	string movies;
	for (unsigned int i = 0; i < this->movies.size(); i++) {
		movies += this->movies[i]->toString();
	}

// just make shure - if no movies - get down one line.
	if (this->movies.size() != 0) {
		this->out->printSomething(movies);
	} else {
		this->out->printSomething("\n");
	}

}

void Imdb::printAllExperts() {

	string experts;
	for (unsigned int i = 0; i < this->experts.size(); i++) {
		experts += this->experts[i]->toString();
	}

// just make shure - if no experts - get down one line.
	if (this->experts.size() != 0) {
		this->out->printSomething(experts);
	} else {
		this->out->printSomething("\n");
	}

}

void Imdb::rankSingleMovie(string code, double singleRank) {
}

void Imdb::printSingleMovie(string movieCode) {
	bool legality = false;
// first check input is legal:
	Movie* mov = getMovie(movieCode);
	if (mov != NULL) {
		this->out->printSomething(mov->toString());
	} else {
		this->out->printActionLegality(legality);
	}
}

void Imdb::printMovieCrew(string movieCode) {

	bool legality = false;
// first check input is legal:
	Movie* mov = getMovie(movieCode);
	if (mov != NULL) {
		this->out->printSomething(mov->getCrewStr());
	} else {
		this->out->printActionLegality(legality);
	}

}

vector<Expert*> Imdb::getExperts() {
	return this->experts;
}

string Imdb::getOutput() {

	return this->out->getOutput();

}

vector<Genre*> Imdb::getGenres() {
	return this->genres;
}

vector<Movie*> Imdb::getMovies() {
	return this->movies;
}

void Imdb::addGenre(string name) {
	this->genres.push_back(new Genre(name));

}

void Imdb::removeGenre(string name) {
	Genre* gen = getGenre(name);

	vector<Genre*>::iterator position = find(this->genres.begin(),
			this->genres.end(), gen);

	if (position != this->genres.end()) { // ==  mov->getCrew()[i]->getMovies().end() means the element was not found
		this->genres.erase(position);
	}

}

Genre* Imdb::getGenre(string name) {

	Genre* genre = NULL;

	for (unsigned int i = 0; i < this->genres.size(); i++) {
		// we look for genre by its name.
		if (this->genres.at(i)->getName().compare(name) == 0) {
			genre = this->genres.at(i);
			break;
		}
	}
	return genre;
}

