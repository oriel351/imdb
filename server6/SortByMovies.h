/****************************************
* Student Name: Oriel Gaash             *
* Exercise Name: assignment 3           *
* File description:  behaviour of sort  *
* method by number of movies.          *
****************************************/






#ifndef INCLUDE_SORTBYMOVIES_H_
#define INCLUDE_SORTBYMOVIES_H_


#include "Expert.h"

class SortByMovies {

public:

	SortByMovies();
	virtual ~SortByMovies();

	bool operator()( const Expert* exp1,  const Expert* exp2) const;


};



#endif /* INCLUDE_SORTBYMOVIES_H_ */
