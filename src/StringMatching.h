/*
 * StringMatching.h
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#ifndef SRC_STRINGMATCHING_H_
#define SRC_STRINGMATCHING_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cctype>

using namespace std;

void KnuthMorrisPratt(vector<string> moradas, string cadeia);

void prefixFunction(string c);

int stringMatching(string morada, string c);

#endif /* SRC_STRINGMATCHING_H_ */
