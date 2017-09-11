/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: defines the behaviou
 * of Writer							*
 ****************************************/

#ifndef INCLUDE_WRITER_H_
#define INCLUDE_WRITER_H_

#include "Expert.h"

using namespace std;

class Writer : public Expert {

public:

/**
* constructor.
* @param id expers ID.
* @param name of expert.
* @param descript description of expert(Writer is defferent
* job from others)
* @param age of expert.
* @param gender male/female.
*/
Writer(long id, int age, string descript, string gender, string name);

/**
 * print's actor's specific description.
 */
virtual string toString();

};


#endif /* INCLUDE_WRITER_H_ */
