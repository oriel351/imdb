/*
 * Director.h
 *
 *  Created on: Nov 21, 2015
 *      Author: oriel
 */

#ifndef INCLUDE_DIRECTOR_H_
#define INCLUDE_DIRECTOR_H_


#include "Expert.h"

using namespace std;


class Director : public Expert {


public:

/**
* constructor.
* @param id expers ID.
* @param name of expert.
* @param description of expert(director is defferent
* job from dothers)
* @param age of expert.
* @param gender male/female.
*/
Director(long id, int age, string descript, string gender, string name);

/**
 * print's actor's specific description.
 */
virtual string toString();

};



#endif /* INCLUDE_DIRECTOR_H_ */
