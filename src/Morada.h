/*
 * Morada.h
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#ifndef SRC_MORADA_H_
#define SRC_MORADA_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Moradas{
	vector<string> moradas; // guarda as moradas lidas do txt
public:
	Moradas();
	void addMoradas(string m);
	vector<string> getMoradas();
	int numMoradas();

};


#endif /* SRC_MORADA_H_ */
