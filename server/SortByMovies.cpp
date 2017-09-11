/****************************************
* Student Name: Oriel Gaash             *
* Exercise Name: assignment 3           *
* File description:            *
****************************************/

#include "SortByMovies.h"

SortByMovies::SortByMovies() {
}

SortByMovies::~SortByMovies() {
}



bool SortByMovies::operator ()(const Expert* exp1, const Expert* exp2) const {

	return (exp1->getMovies().size() >= exp2->getMovies().size() );

}






