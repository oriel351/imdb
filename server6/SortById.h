/****************************************
* Student Name: Oriel Gaash             *
* Exercise Name: assignment 3           *
* File description:            *
****************************************/






#ifndef INCLUDE_SORTBYID_H_
#define INCLUDE_SORTBYID_H_


#include "Expert.h"

class SortById {

public:

	SortById();
	virtual ~SortById();

	bool operator()( const Expert* exp1,  const Expert* exp2) const;


};


#endif /* INCLUDE_SORTBYID_H_ */
