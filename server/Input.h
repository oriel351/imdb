/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: this file enchaeged *
 * of get all the inputs from the console*
 ****************************************/

#ifndef INCLUDE_INPUT_CPP_
#define INCLUDE_INPUT_CPP_

using namespace std;

#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>

class Imdb;

#define END_PROGRAM "-1"
#define GET_NEW_MOVIE "1"
#define GET_NEW_EXPERT "2"
#define ADD_EXPERT_TO_MOVIE "3"
#define BELONG_MOVIE_TO_GENRE "4"
#define SORT_EXPERTS_OF_MOVIE "5"
#define PRINT_EXPERTS_OF_MOVIE "6"
#define PRINT_MOVIE "7"
#define JOIN_MOVIES "8"
#define PRINT_EXPERT_MOVIES "9"
#define DELETE_MOVIE "10"
#define DELETE_EXPERT "11"
#define REMOVE_EXPERT_FROM_MOVIE "12"
#define PRINT_ALL_MOVIES "13"
#define PRINT_ALL_EXPERTS "14"
#define PRINT_BY_GENRE "15"

/**
 * this class will be used to manage the input from the console.
 * and create objects as neede and add them to an existing
 * imdb system.
 */

class Input {

private:

	Imdb* system;
	vector<string> data;

public:

	Input(Imdb* db);

	/**
	 * this function parses the string received in buffer into separated stings.
	 * later each function uses the parsed string as it needs.
	 */
	void splitCommandLine(char* commandNum, char* commandLine);

	/**
	 * this function sends the information got and activates the command crresponding to the
	 * command Number.
	 */
	void streamInput(char* commandNum, char* commandLine);

	/*
	 * gets the parameters for a new movie.
	 * and adds the movie to database, if legal.
	 **/
	void inputMovie();

	/**
	 * gets parameters for expert.
	 */
	void inputExpert();

	/**
	 * belong exeprt to movie.
	 */
	void belongExpertToMovie();

	/**
	 *gets parameters to belong a movie to a genre
	 */
	void belongMovieToGenre();

	/**
	 *	gets sorting paramaetr and sorts the movie
	 */
	void sortMovie();

	/**
	 *	gets movie code and prints it's crew
	 */
	void printCrewOfMovie();

	/**
	 * prints all the details of a certain movie.
	 */
	void printMovie();

	/**
	 * get a line of codes to movies and joins them all
	 */
	void joinMovies();

	/**
	 * print movies by expert.
	 */
	void printExpertMovies();

	/**
	 * delete a movie from database.
	 */
	void deleteMovie();

	/**
	 * delete an expert from database.
	 */
	void deleteExpert();

	/**
	 * remove an expert from a movie.
	 */
	void removeExpertFromMovie();

	/**
	 * print all the movies in database.
	 */
	void printAllMovies();

	/**
	 * print all the experts in database.
	 */
	void printAllExperts();

	/**
	 * print movies by genre.
	 */
	void printByGenre();

};

#endif /* INCLUDE_INPUT_CPP_ */
