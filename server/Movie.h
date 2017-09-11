/*
 * Movie.h
 *
 *  Created on: Nov 21, 2015
 *  Author: oriel
 * 8921004 302462825 Oriel Gaash */

/****************************************
 * Student Name:  oriel gaash              *
 * Exercise Name: exercise 3              *
 * File description: all movie's functions             *
 ****************************************/
#ifndef INCLUDE_MOVIE_H_
#define INCLUDE_MOVIE_H_

#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
class Genre;
class SortById;
class SortByAge;
class SortByMovies;
class Expert;

using namespace std;

class Movie {

	friend class Imdb;
private:

	string code;
	string name;
	int length;
	int kushilipepo; // because of stupid compiler getLength didnt work.
	// just a copy of length.
	int year;
	int sortMethod;
	double rank;
	string imageLink;
	string description;
	int timesRanked;
	vector<Expert*> crew;
	vector<Genre*> genres;

public:
	/******************************************************************
	 * constructor.
	 * @param code the movie's code.
	 * @param name of the movie.
	 * @param length of the movie.
	 * @param year the movie created.
	 * @param rank the movies rank ( 0 - 10) *
	 * @param imageLink an http link to an image of the movie on the web.
	 * sort default is 1.
	 ******************************************************************/
	Movie(string code, string name, int length, int year, double rank,
			string imageLink, string descript);

	/******************************************************************
	 * 2nd constructor.
	 * this is use to join movies.
	 * @param maxLength movie , which we get most details of.
	 * @param crew, the joined list of crew.
	 * @param genres the joined list of genres.
	 ******************************************************************/
	Movie(Movie* maxLengthMov, const vector<Expert*>& crew,
			const vector<Genre*>& genres, string joinedCode);
	/*******************************************************************
	 * destructor.
	 ******************************************************************/
	~Movie();

	/**
	 * this is exactly the length.
	 * for some reason, getLength function doesnt work.
	 */
	int getKush();
	/*******************************************************************
	 * add a member to a movie
	 * @param persom a pointer to the member to add to list.
	 *******************************************************************/
	bool addMember(Expert* person);

	/**
	 * returns the length of movie.
	 **/
	int getLength();

	/*******************************************************************
	 * removes an expert from the list of the movie's experts.
	 * @param exp the member which will be removed.
	 * @return true if member was found and succusfuly removed,
	 * else otherwise.
	 *******************************************************************/
	bool removeMember(Expert* exp);

	/*******************************************************************
	 * sets the sorting method of experts for current movie.
	 * @param param is the way of sorting (see Imdb class for detail.)
	 *******************************************************************/
	void setSortingMethod(int param);

	/*******************************************************************
	 * prints the current movie info, including experts,
	 * by the sorting method.
	 *******************************************************************/
	string toString();

	/**
	 * returns a string containing all the genres movies belongs to.
	 */
	string getGenresNames();
	/*******************************************************************
	 * prints the current movie's crew, by the current sorting method.
	 *******************************************************************/
	string getCrewStr();

	/*******************************************************************
	 * returns the movie's code
	 *******************************************************************/
	string getCode();

	/**
	 * returns an expert by its id
	 * @param id  member's id we are lokking for.
	 * @return pointer to a expert, NULL if doesnt exist.
	 */
	Expert* getExpert(long id);

	/**
	 * returns a genre if exists, NULL otherwise.
	 */
	Genre* getGenre(string name);

	/*******************************************************************
	 * returns the list of crew.
	 *******************************************************************/
	vector<Expert*> getCrew();

	/*******************************************************************
	 * returns the list of genres.
	 *******************************************************************/
	vector<Genre*> getGenres();

	/*********************************************************************
	 * returns the name of movie.
	 ********************************************************************/
	string getName();

	/*********************************************************************
	 * returns the rank of the movie.
	 ********************************************************************/
	double getRank();

	/*********************************************************************
	 * this function applies a user's rank and updates the movie's rank.
	 * @param userRank the user's opinio of the rank. ( values 1 - 10).
	 ********************************************************************/
	void applyUserRank(double userRank);

	/*********************************************************************
	 * returns the current sorting way.
	 ********************************************************************/
	int getSort();

	/**
	 * sort the the experts in the movie.
	 * depends on this-> sortMethod member.
	 * 1 - by ID
	 * 2 - by Age
	 * 3 - by number of movies.
	 * default - by ID.
	 */
	void sortNow();

	/****
	 * returns the year movie out.
	 ***/
	int getYear();

	/**
	 * returns movie description.
	 */
	string getDescription();

	/**
	 * belongs a genre to this movie.
	 * returns true if succeded and belonged a new genre, false otherwise.
	 */
	bool belongGenre(Genre* genre);

	/**
	 * joins two movies .
	 */
	Movie* joinMovies(Movie* mov2);

	/**
	 * joins the list of genres of two movies.
	 */
	vector<Genre*> joinGenres(Movie* mov2);

	/**
	 * joins the list of crew of two movies.
	 */
	vector<Expert*> joinExperts(Movie* mov2);

};

#endif /* INCLUDE_MOVIE_H_ */

