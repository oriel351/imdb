/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: takes care of outpu *
 * of the system                         *
 ****************************************/

#ifndef INCLUDE_OUTPUT_H_
#define INCLUDE_OUTPUT_H_

#include <iostream>

using namespace std;


class Output {

	private:

	string output;

public:

	Output();

	virtual ~Output();

	void printActionLegality(bool status);

	void printSomething(string output);

	string getOutput();
};

#endif /* INCLUDE_OUTPUT_H_ */
