/*
 * Files.cpp
 *
 *  Created on: 14/05/2015
 *      Author: Filipa
 */

#include "Files.h"


File::File(string n){
	this->file_name = n;
}

int File::readFile(){

	ifstream file;
	file.open(file_name.c_str());


}

