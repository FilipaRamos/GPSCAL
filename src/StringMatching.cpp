/*
 * StringMatching.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "StringMatching.h"

using namespace std;

string p = "cocacola"; //palavra a ser testada
int prefix[8];

void KnuthMorrisPratt(string morada){

	for(int i = 0; i < morada.length(); i++){

	}
}

void prefixFunction(){

	prefix[0] = 0;
	int a = 0;
	int len = p.length();


	for(int b = 1; b < 8; b++){

		while(a>0 && p[a] != p[b]){
			a = prefix[a];
		}

		if(p[a] == p[b]){
			a +=1;
		}

		prefix[b] = a ;
	}

	for(int i=0 ; i < p.length() ; i++){
		cout << prefix[i] << "\n";
	}

	cout << endl;
}

void stringMatcging(){
	string T ; //frase a ser testada
	int n = T.length();
	int m = p.length();
	int j;
	int k;
	int i = j = k = 0;


	while(n-k >= m){
		while( j <= m && T[i] = p[j]){
			i++;
			j++;
		}

	}




}
