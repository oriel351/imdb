/****************************************
* Student Name: Oriel Gaash             *
* Exercise Name: assignment 3           *
* File description: implements sort by *
* age behaviour				           *
****************************************/

#include "SortByAge.h"
#include "Expert.h"

SortByAge::SortByAge() {}


SortByAge::~SortByAge() {}


bool SortByAge::operator ()(const Expert* exp1, const Expert* exp2) const {

	return (exp1->getAge() >= exp2->getAge() );
}









