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

void cls(HANDLE hConsole, int size_pesquisa);

int main() {

	PrefixTree pf;
	vector<string> info;
	vector<string> result;
	string pesquisa;
	int opcao;
	char line[256];
	File f = File("teste.txt");
	f.readFile();
	int c;

	SMALL_RECT srctWriteRect;

	cout << " BEM VINDO AO SISTEMA DE GPS! " << endl;
	cout << "--------------------------------" << endl;
	cout << "A carregar a informacao..." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);
	cout << endl;
	cout << "A estabelecer a coneccao..." << endl;
	cout << "--------------------------------" << endl;
	Sleep(1000);

	cout << "\nEscolha o algoritmo preferido : " << endl;
	cout << "1. Knuth-Morris-Pratt" << endl;
	cout << "2. Arvore de Prefixos" << endl << endl;

	cin >> opcao;

	cout << endl;
	cout << "Introduza morada : " << endl;

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
		cerr << "Erro obter info consola!";
	}

	//	SMALL_RECT rect;
	//	rect.Top=0; rect.Left = 0;
	//	rect.Bottom = 45;
	//	rect.Right = 80;
	//
	//	if (!SetConsoleWindowInfo(hStdout, FALSE, &rect)) {
	//		cerr << "erro redimendisonar janela!";
	//	}

	while (true) {

		int c = _getch();

		cls(hStdout, pesquisa.length());

		cout << (char) c << endl;
		if (c == 8 && pesquisa.length() > 0) {
			pesquisa = pesquisa.substr(0, pesquisa.length() - 1);
		} else if (c != 13 && c != 10) {
			pesquisa = pesquisa + (char) c;
		} else {
			continue;
		}


		if (c != 13 && c != 10) {
			switch (opcao) {
			case 1:
			{
				KnuthMorrisPratt(f.getMoradas(), pesquisa);
			}
			break;
			case 2:
				info = f.getMoradas();
				for (int i = 0; i < info.size(); i++) {
					pf.insert(info[i]);
				}
				result = pf.complete(pesquisa);
				for (int j = 0; j < result.size(); j++) {
					cout << result[j] << endl;
				}
				break;
			default:
				break;
			}
		}

		//cout << endl << endl << pesquisa;
	}

	cin.get();
	return 0;
}

void cls(HANDLE hConsole, int size_pesquisa) {
	COORD coordScreen = { size_pesquisa, 16 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole, // Handle to console screen buffer
			(TCHAR) ' ',     // Character to write to the buffer
			dwConSize,       // Number of cells to write
			coordScreen,     // Coordinates of first cell
			&cCharsWritten))     // Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole, // Handle to console screen buffer
			csbi.wAttributes, // Character attributes to use
			dwConSize,        // Number of cells to set attribute
			coordScreen,      // Coordinates of first cell
			&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);

	//cout << csbi.srWindow.Bottom << "\t" << csbi.srWindow.Right;

}
