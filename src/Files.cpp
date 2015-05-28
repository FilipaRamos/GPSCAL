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

<<<<<<< HEAD
bool File::readFile(){

	string linha;
=======
bool File::readFile(string keyword){
>>>>>>> origin/master
	ifstream file;
	file.open(file_name.c_str());

	if(file.is_open()){
		while(!file.eof()){
			getline(file, linha);
			Morada(linha);
		}
	}

}

