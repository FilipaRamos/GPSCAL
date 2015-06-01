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
	for(unsigned int i = 0; i < moradas.size(); i++){
		string s;
		for(unsigned int j = 0; j < moradas[i].length(); j++){
			s += putchar (tolower(moradas[i][j]));
		}
		moradas_min.push_back(s);
	}

	cout << moradas_min[0] << endl;
}
