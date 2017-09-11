/*
 * Genre.h
 *
 *  Created on: Nov 21, 2015
 *      Author: oriel
 */

#ifndef INCLUDE_GENRE_H_
#define INCLUDE_GENRE_H_

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Movie;

/**
 * this class defines the genres in the database.
 * each object will handle a single gnre, and have references to movies int the genre.
 * each object will have a unique and know code.
 * for exxample - 1 - horror. 2 - comedy. etc...
 */
class Genre {

private:

	string name;

	// this way we could always easily get a list of movies by specific genre :
	vector<Movie*> movies;

public:
	/**
	 * constructor.
	 * @param name of genre ('action', 'comedy', etc..)
	 */
	Genre(string name);
	/**
	 * adds a movie to be classified as current genre.
	 * always inserts sorte, i.e keeps the movies in a
	 * alphabetic order
	 */

	/**
	 * destructor.
	 * frees memory.
	 */
	~Genre();
	bool addMovie(Movie* movie);
	/**
	 * removes a movie from current genre.
	 * @param code of the movie to be removed.
	 */
	void removeMovie(Movie* movie);

	/**
	 * returns the list of movies classified as current genre.
	 */
	vector<Movie*> getMovies();
	/**
	 * returns the name of the current genre.
	 */
	string getName();

	/**
	 *
	 */
	Movie* getMovie(string code);

};

#endif /* INCLUDE_GENRE_H_ */

