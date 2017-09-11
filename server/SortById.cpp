/****************************************
* Student Name: Oriel Gaash             *
* Exercise Name: assignment 3           *
* File description: implements sort by  *
*  id 							         *
****************************************/

#include "SortById.h"


SortById::SortById() {
}

SortById::~SortById() {
}

bool SortById::operator ()(const Expert* exp1, const Expert* exp2) const {

	return (exp1->getId() <= exp2->getId() );

}








