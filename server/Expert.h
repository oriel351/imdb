/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: all the behaviour of *
 * an exprt is defined here.	         *
 ****************************************/

#ifndef INCLUDE_EXPERT_H_
#define INCLUDE_EXPERT_H_

#include <algorithm>
#include <string>
#include <vector>

class Movie;

using namespace std;


class Expert {

	friend class Imdb;
protected:

	long id;
	int age;
	string gender;
	string name;
	string description;
	vector<Movie*> movies;

public:

	/**
	 * constructor.
	 * @param identity expers ID.
	 * @param name of expert.
	 * @param description of expert(aACH DIIFERENT CREW TEAM HAS A DIFFERENT)
	 * @param age of expert.
	 * @param gender male/female.
	 */
	Expert(long id, int age, string descript, string gender, string name);
	// id, age, description, gender, name
	/**
	 * d'structor.
	 */
	virtual ~Expert();
	/**
	 * prints the current Expert's info and job description.
	 */
	virtual string toString();

	/**
	 * returns the current expert's ID.
	 */
	long getId() const;

	/**
	 * returns the age.
	 */
	int getAge() const;

	/*** return the list of movies participating.
	 */
	vector<Movie*> getMovies() const;

	/**
	 * belongs a given movie to current expert.
	 * @param movie to add.
	 * @return treu if succeded, false otherwisse.
	 */
	bool addMovie(Movie* movie);

	/**
	 *
	 */
	Movie* getMovie(string code);

	bool removeMovie(Movie* movie);
	/**
	 * prints all the movies current expert
	 * participating.
	 */
	void printMovies();

	string getDescription();

	string getGender();

	string getName();

};

#endif /* INCLUDE_EXPERT_H_ */
