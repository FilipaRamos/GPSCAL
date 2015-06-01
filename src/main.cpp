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
#include <stdio.h>
#include <ctype.h>
#include "StringMatching.h"
#include "Files.h"
#include "Morada.h"
#include "PrefixTree.h"

using namespace std;

int main() {

	PrefixTree pf;
	vector<string> info;
	vector<string> result;
	string pesquisa;
	string s;
	int opcao;
	char line[256];
	File f = File("teste.txt");
	f.readFile();

	cout << " BEM VINDO AO SISTEMA DE GPS! " << endl;
	cout << "--------------------------------" << endl;
	cout << "A carregar a informa��o...." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);
	cout << endl;
	cout << "A estabelecer a conec��o...." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);
	cout << endl;
	cout << "Introduza morada : " << endl;
	getline(cin, pesquisa);

	for(unsigned int i = 0; i < pesquisa.length(); i++){
		s += putchar (tolower(pesquisa[i]));
	}

	cout << "Escolha o algoritmo preferido : " << endl;
	cout << "1. Knuth-Morris-Pratt" << endl;
	cout << "2. �rvore de Prefixos" << endl;

	cin >> opcao;

<<<<<<< HEAD

	switch (opcao) {
	case 1:
		KnuthMorrisPratt(f.getMoradas(), s);
=======
	File f = File("teste.txt");
		f.readFile();

	switch(opcao){

	case 1:
		//f.format();

		KnuthMorrisPratt(f.getMoradas(), pesquisa);

>>>>>>> origin/master
		break;
	case 2:
		info = f.getMoradas();
		for (int i = 0; i < info.size(); i++){
			pf.insert(info[i]);
		}
		result = pf.complete(pesquisa);
		for (int j = 0; j < result.size(); j++){
			cout << result[j] << endl;
		}
		break;
	default:
		break;
	}

	return 0;
}

