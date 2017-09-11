/*
 * Actor.h
 *
 *  Created on: Nov 21, 2015
 *      Author: oriel Gaash.
 *      ID : 302462825.
 */

#ifndef INCLUDE_ACTOR_H_
#define INCLUDE_ACTOR_H_

#include "Expert.h"
#include <sstream>

using namespace std;


class Actor : public Expert {


public:

/**
* constructor.
* @param identity expers ID.
* @param name of expert.
* @param description of expert(actor is defferent
* job from actor).
* @param age of expert.
* @param gender male/female.
*/
Actor(long id, int age, string descript, string gender, string name);

/**
 * print's actor's specific description.
 */
virtual string toString();

};


#endif /* INCLUDE_ACTOR_H_ */
