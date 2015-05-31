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
#include "PrefixTree.h"

using namespace std;

int main(){

	PrefixTree pf;
	vector<string> info;
	vector<string> result;
	string pesquisa;
	int opcao;

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

	cout << "Escolha o algoritmo preferido : " << endl;
	cout << "1. Knuth-Morris-Pratt" << endl;
	cout << "2. Árvore de Prefixos" << endl;

	cin >> opcao;

	File f = File("teste.txt");
	f.readFile();

	switch(opcao){

	case 1:
		KnuthMorrisPratt(f.getMoradas(), pesquisa);
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


