/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: behaviour of
 * producer								*
 ****************************************/

#ifndef INCLUDE_PRODUCER_H_
#define INCLUDE_PRODUCER_H_


#include "Expert.h"

using namespace std;



class Producer: public Expert {


public:

/**
* constructor.
* @param identity expers ID.
* @param name of expert.
* @param description of expert(producer is defferent
* job from others)
* @param age of expert.
* @param gender male/female.
*/
Producer(long id, int age, string descript, string gender, string name);

/**
 * print's actor's specific description.
 */
virtual string toString();

};

#endif /* INCLUDE_Producer_H_ */

