/*
 * Morada.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "Morada.h"

using namespace std;

Moradas::Moradas(string m){
	moradas.push_back(m);
}

vector<string> Moradas::getMoradas(){
	return moradas;
}

int Moradas::numMoradas(){
	return moradas.size();
}

