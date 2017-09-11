/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: this file encharged *
 * ofhandling all aspects of movie object*
 ****************************************/

#include "Movie.h"
#include "Expert.h"
#include "SortByAge.h"
#include "SortById.h"
#include "SortByMovies.h"
#include "Genre.h"

using namespace std;

#define DEFAULT_SORT_METHOD 1
#define INITIAL_RANK_TIMES 0 // this is for future, we can add user rank system.

Movie::Movie(string code, string name, int length2, int year, double rank,
		string imageLink, string descript) {

	this->code = code;
	this->name = name;
	this->length = length2;
	this->year = year;
	this->timesRanked = INITIAL_RANK_TIMES;
	this->rank = rank;
	this->imageLink = imageLink;
	this->sortMethod = DEFAULT_SORT_METHOD;  // default sort !
	this->description = descript;
	this->kushilipepo = length2;

}

Movie::Movie(Movie* maxLengthMov, const vector<Expert*>& crew,
		const vector<Genre*>& genres, string joinedCode) {

	this->code = joinedCode;
	this->name = maxLengthMov->name;
	this->length = maxLengthMov->length;
	this->year = maxLengthMov->length;
	this->timesRanked = INITIAL_RANK_TIMES;
	this->rank = maxLengthMov->rank;
	this->imageLink = maxLengthMov->imageLink;
	this->sortMethod = DEFAULT_SORT_METHOD;  // default sort !
	this->description = maxLengthMov->description;
	this->crew = crew;
	this->genres = genres;
	this->kushilipepo = maxLengthMov->length;
	;

}

int Movie::getKush() {
	return this->kushilipepo;
}
string Movie::getCode() {
	return this->code;

}

Expert* Movie::getExpert(long id) {
	Expert* exp = NULL;
	for (unsigned int i = 0; i < this->crew.size(); i++) {

		// if we find a code identical already in db
		if (this->crew.at(i)->getId() == id) {
			exp = crew.at(i);
			break;
		}
	}
	return exp;

}

Genre* Movie::getGenre(string name) {

	Genre* genre = NULL;

	for (unsigned int i = 0; i < this->genres.size(); i++) {
		// we look for genre by its name.
		if (this->genres[i]->getName().compare(name) == 0) {
			genre = this->genres[i];
			break;
		}
	}
	return genre;
}

bool Movie::addMember(Expert* person) {

	// checking exists.
	if (getExpert(person->getId()) == NULL) {
		this->crew.push_back(person);
		return true;
	}
	// if exists already, isn't added , returns false;
	return false;

}

bool Movie::removeMember(Expert* exp) {

	vector<Expert*>::iterator position = find(this->crew.begin(),
			this->crew.end(), exp);

	if (position != this->crew.end()) { // ==  mov->getCrew()[i]->getMovies().end() means the element was not found
		this->crew.erase(position);
		return true;
	} else {
		return false;
	}

}

void Movie::setSortingMethod(int param) {
	this->sortMethod = param;
}

string Movie::toString() {

	string movie, crew;

	// buffers comverting to string:

	stringstream length, year, rank;
	length << this->length;
	year << this->year;
	rank << this->rank;

	// getting  MOVIE INFO:

	movie = this->code + " " + this->name + " " + length.str() + " "
			+ year.str() + " " + rank.str() + " " + getGenresNames()
			+ this->description + "\n";

	//getting EXPERTS INFO,(ONLY IF NEEDED)
	if (this->crew.size() > 0) {
		crew = getCrewStr();
	}

	return movie + crew;

}

string Movie::getGenresNames() {
	string genres;
	for (unsigned int i = 0; i < this->genres.size(); i++) {
		genres += this->genres[i]->getName();
		if (i < this->genres.size() - 1) {
			genres += ",";
		}
	}
	if (this->genres.size() > 0) {
		genres += " ";
	}
	return genres;
}
string Movie::getCrewStr() {
	string crew;
	for (unsigned int i = 0; i < this->crew.size(); i++) {
		crew += this->crew.at(i)->toString();
	}
	// this is to make shure the is one line gap, even empty crew.
	if (crew.size() == 0) {
		crew = "\n";
	}
	return crew;

}

vector<Expert*> Movie::getCrew() {
	return this->crew;
}

vector<Genre*> Movie::getGenres() {
	return this->genres;
}

int Movie::getLength() {
	return this->length;
}

string Movie::getName() {
	return this->name;
}

double Movie::getRank() {
	return this->rank;
}

void Movie::applyUserRank(double userRank) {
	/*
	 * validating correct input between 1 - 10
	 * note : this will be validated as well at the imdb class.
	 */
}

int Movie::getSort() {
	return this->sortMethod;;
}

void Movie::sortNow() {

	switch (this->sortMethod) {

	case 1:
		sort(this->crew.begin(), this->crew.end(), SortById());
		break;
	case 2:
		sort(this->crew.begin(), this->crew.end(), SortByAge());
		break;
	case 3:
		sort(this->crew.begin(), this->crew.end(), SortByMovies());
		break;
	default:
		// the same as option 1.
		sort(this->crew.begin(), this->crew.end(), SortByAge());
		break;
	}

}

int Movie::getYear() {
	return this->year;
}

Movie::~Movie() {
}

bool Movie::belongGenre(Genre* genre) {

// if does not exist, insert, otherwise, do nothing, return false.
	if (getGenre(genre->getName()) == NULL) {
		this->genres.push_back(genre);
		return true;
	} else {
		return false;
	}

}

Movie* Movie::joinMovies(Movie* mov2) {
	/**
	 * first merge the genres and experts lists, and code.
	 */

	string joinedCode = this->code + "_" + mov2->code;
	/**
	 * getting the informaion from the longest movie.
	 * if equal the length, taking details from the left ( this , mov1)
	 */
	Movie* longer;
	if (this->length >= mov2->length) {

		longer = this;
		// return new Movie(this, joinExp, joinGen, joinedCode);

	} else {
		longer = mov2;
		// return new Movie(mov2, joinExp, joinGen, joinedCode);
	}

	return new Movie(longer, this->joinExperts(mov2), this->joinGenres(mov2),
			joinedCode);

}

vector<Genre*> Movie::joinGenres(Movie* mov2) {

// merging genres :
	vector<Genre*> joinGen = this->genres;

	for (unsigned int i = 0; i < mov2->genres.size(); i++) {
		/**
		 *  pushing genre from mov2 after validating it's not
		 *  on mov1 (this) as well.
		 */
		if (this->getGenre(mov2->genres[i]->getName()) == NULL) {
			joinGen.push_back(mov2->genres[i]);
		}
	}

	return joinGen;

}

vector<Expert*> Movie::joinExperts(Movie* mov2) {

// merging crew first :

	vector<Expert*> joinExp = this->crew;
	for (unsigned int i = 0; i < mov2->crew.size(); i++) {

		/**
		 *  pushing crew member from mov2 after validating it's not
		 *  on mov1 (this) as well.
		 */
		if (this->getExpert(mov2->crew[i]->getId()) == NULL) {
			joinExp.push_back(mov2->crew[i]);
		}
	}

	return joinExp;
}

string Movie::getDescription() {
	return this->description;
}

