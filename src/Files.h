/*
 * Files.h
 *
 *  Created on: 14/05/2015
 *      Author: Filipa
 */

#ifndef FILES_H_
#define FILES_H_

#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "Morada.h"

using namespace std;

class File{
	string file_name;
	vector<string> moradas;
	public:
		File(string n);
		void readFile();
		vector<string> getMoradas();
		void format(string s);
};



#endif /* FILES_H_ */
