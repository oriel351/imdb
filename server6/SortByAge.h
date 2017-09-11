/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description:    sorthing behaviour
 * by age    							    *
 ****************************************/

#ifndef INCLUDE_SORTBYAGE_H_
#define INCLUDE_SORTBYAGE_H_

// class Expert;
class Expert;

class SortByAge {

public:

	SortByAge();
	virtual ~SortByAge();

	bool operator()(const Expert* exp1, const Expert* exp2) const;

};

#endif /* INCLUDE_SORTBYAGE_H_ */
