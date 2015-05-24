/*
 * Files.cpp
 *
 *  Created on: 14/05/2015
 *      Author: Filipa
 */

#include "Files.h"
#include <istream>


File::File(string n){
	file_name = n;
}

bool File::readFile(string keyword){

	ifstream file;
	file.open(file_name.c_str());

	if(file.is_open()){
	}

}

