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

int main() {

	string pesquisa;
	int opcao;
	char line[256];

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

	switch (opcao) {

	case 1: {
		File f = File("teste.txt");
		f.readFile();
		KnuthMorrisPratt(f.getMoradas(), pesquisa);
	}
		break;
	case 2:
		break;
	default:
		break;
	}

	File f = File("teste.txt");
	f.readFile();
	KnuthMorrisPratt(f.getMoradas(), pesquisa);

	return 0;
}

