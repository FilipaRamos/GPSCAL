/*
 * Files.cpp
 *
 *  Created on: 14/05/2015
 *      Author: Filipa
 */

#include "Files.h"

File::File(string n){
	file_name = n;
}

void File::readFile(){

	string linha;
	ifstream file;
	file.open(file_name.c_str());

	if(file.is_open()){
		while(!file.eof()){
			getline(file, linha);
			moradas.push_back(linha);
		}
	}
	else
		cout << "ERROR READING FILE!" << endl;
}

vector<string> File::getMoradas(){
	return moradas;
}

void  File::format(){
	int i = 0;
	char c;

	for(unsigned int k = 0; k < moradas.size(); k++){
		while (moradas[k][i]) {
			c = moradas[k][i];
			if (isupper(c))
				c = tolower(c);
			putchar(c);
			i++;
		}
	}
}
