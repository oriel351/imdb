/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: this file enchaeged *
 * of all the system image database.     *
 ****************************************/
#ifndef INCLUDE_IMDB_H_
#define INCLUDE_IMDB_H_

#include <string>
#include <vector>
#include <pthread.h>

class Output;
class Input;
class Movie;
class Expert;
class Genre;

using namespace std;

enum {
	DIRECTOR, ACTOR, WRITER, PRODUCER
};

// this is the lock which will be used to prevent multi instances
static pthread_mutex_t lock;

class Imdb {

	friend class Input;

private:

	Input* in;
	Output* out;
	vector<Movie*> movies;
	vector<Expert*> experts;
	vector<Genre*> genres;

	Imdb(); // prevent the class instantiation

public:

	/**
	 * constructor.
	 */
	static Imdb* getInstance();

	/**
	 * destructor, free memory.
	 */
	~Imdb();

	/**
	 *
	 */
	void pushCommand(char* commandNum, char* commandLine);

	string getOutput();
	/*
	 * adds a new movie to the database
	 * @param movie the movie added.
	 *
	 **/
	void addMovie(string code, string name, int length, int year, double rank,
			string imageLink, string descript);

	/**
	 * removes a movie from the database
	 * @param code the movie's code.
	 */
	void removeMovie(string code);

	/**
	 * returns a pointer to a movie by it's code
	 * @param code the movie we want code's
	 */
	Movie* getMovie(string code);

	/**
	 * adds an expert to the database.
	 * adds the correct type accordind to param type.
	 * @param type of the expert.
	 * 0 - director, 1 - actor, 2 - writer, 3 - producer.
	 * @param id of the expert.
	 * @param age of the expert.
	 * @param description of the job.
	 * @param gender of the expert.
	 * @param name of the expert.
	 */
	void addExpert(int type, long id, int age, string description,
			string gender, string name);
	/**
	 * adds a new crew to the list of a certain movie.
	 * validating if expert exists in movie, but only in movie's class.
	 * (we assume if  checked at movie class, and actions are alwasy together,
	 * guaranteed 100% to add pointers in both classes, and remove in both.
	 * @param expert the current expert added.
	 */
	void belongExpertToMovie(string movieCode, long id);

	/**
	 * removes an expert from some movie.
	 * @param movieCode from which movie to remove.
	 * @param expertID the expert's identification.
	 */
	void removeExpert(long expertId);

	/**
	 * renmoves an expert from a movie.
	 * takes care to remove the pointer of expert from the movie,
	 * and remove pointer of movie from the expert.
	 */
	void removeExpertFromMovie(string movieCode, long expertId);

	/**
	 * checks whether an expert has already been entered before.
	 *
	 */
	Expert* getExpert(long id);

	/**
	 * adds a new genre to the options of genres.(to the imdb's list).
	 * @param name of genre to add the database.
	 */
	void addGenre(string name);

	/**
	 * returns a single genre by its code.
	 * @param code of the genre.
	 */
	Genre* getGenre(string name);
	/**
	 * removes a genre from the database.
	 */
	void removeGenre(string name);

	/**
	 * belongs a specified movie to a genre.
	 * @param movieCode the current movie we belong to.
	 * @param genre the genre we are adding the movie.
	 */
	void belongMovieToGenre(string movieCode, string name);

	/**
	 * this function set's the way experts will be sorted in
	 * a specific movie.
	 * @param movieCode the movie's code.
	 * @param sortParam the parameter indicating the type of sorting.
	 * 1 - by ID.
	 * 2 - by age ( old to young)
	 * 3 - by number of movies participated.
	 */
	void sortMovie(string movieCode, int sortParam);

	/**
	 * joints 2 or more movies, starting from the longest,
	 * to the shortest(in minutes), creating a new movie
	 * int the database.
	 * After the joint, a new movie is added to db - the name is
	 * taken from the longest(and all other data) except genre and
	 * members. are joined together all lists to a new big list.
	 * @param codes a list of desired movies codes to joint.
	 */
	void joinMovies(vector<string> codes);

	/**
	 * this function send's some user rank to a movie, by it's code.
	 * @param code the movie's code.
	 * @param singleRank the user's opino of the movie( value must be between 1 - 10)
	 */
	void rankSingleMovie(string code, double singleRank);
	/**
	 * prints all the movies a specific expert is participating.
	 * @param expertID the expert's identification.
	 */
	void printMoviesByExpert(long expertId);

	/**
	 * prints all movies of certain genre.
	 */
	void printMoviesByGenre(string genreName);
	/**
	 * prints all the movies in the database.
	 */
	void printAllMovies();

	/**
	 * prints all the experts(Actors, writes, etc..)
	 * in the database
	 */
	void printAllExperts();

	/**
	 * prints all the experts for a specific movie.
	 * @param code of the movie whos it's crew we're
	 * printing.
	 */
	void printMovieCrew(string movieCode);

	/**
	 * printing a single movie.
	 * @param movieCode the code of the movie.
	 */
	void printSingleMovie(string movieCode);
	/**
	 * returns the list of experts.
	 */
	vector<Expert*> getExperts();

	/**
	 * returns the list of genres.
	 */
	vector<Genre*> getGenres();

	/**
	 * returns the list of movies.
	 */
	vector<Movie*> getMovies();

	/**
	 * reursively joins movies from array.
	 */
	Movie* join(vector<Movie*> movies, int begin, int size);

};

#endif /* INCLUDE_IMDB_H_ */
