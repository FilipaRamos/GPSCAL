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

void File::readFile(Moradas m){

	string linha;
	ifstream file;
	file.open(file_name.c_str());

	if(file.is_open()){
		while(!file.eof()){
			getline(file, linha);
			m.addMoradas(linha);
		}
	}
	/*else
		cout << "ERROR READING FILE!" << endl;
*/
	file.close();
}

