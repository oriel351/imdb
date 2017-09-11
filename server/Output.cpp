/****************************************
 * Student Name: Oriel Gaash             *
 * Exercise Name: assignment 3           *
 * File description: output implementation*
 ****************************************/

#include "Output.h"

Output::Output() {
}

Output::~Output() {
}

void Output::printActionLegality(bool status) {

	if (status) {
		this->output = "Success \n";
	} else {
		this->output = "Failure \n";
	}

}
void Output::printSomething(string output) {

	this->output = output;
}

string Output::getOutput() {
	return this->output;

}
