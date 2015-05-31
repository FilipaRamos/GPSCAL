/*
 * main.cpp
 *
 *  Created on: 14/05/2015
 *      Author: Filipa
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StringMatching.h"
#include "Files.h"
#include "Morada.h"

using namespace std;

int main(){

	string pesquisa;

	cout << " BEM VINDO AO SISTEMA DE GPS! " << endl;
	cout << "--------------------------------" << endl;
	cout << "A carregar a informação...." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);
	cout << endl;
	cout << "A estabelecer a conecção...." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);
	cout << endl;
	cout << "Introduza morada : " << endl;
	getline(cin, pesquisa);

	File f = File("teste2.txt");
	f.readFile();
	KnuthMorrisPratt(f.getMoradas(), pesquisa);

	return 0;
}


