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
#include "Morada.h"

using namespace std;

class File{
	string file_name;
	public:
		File(string n);
		bool readFile();
};



#endif /* FILES_H_ */
