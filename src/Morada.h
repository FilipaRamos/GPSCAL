/*
 * Morada.h
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#ifndef SRC_MORADA_H_
#define SRC_MORADA_H_

#include "main.cpp"

using namespace std;

class Moradas{
	vector<string> moradas;
public:
	Moradas(string m);
	vector<string> getMoradas();
	int numMoradas();

};


#endif /* SRC_MORADA_H_ */
