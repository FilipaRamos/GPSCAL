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

void stringMatching(){
	prefixFunction();

	string T = "cozacocacolacococacola" ; //frase a ser testada
	int n = T.length();
	int m = p.length();

	cout << "n: " << n << " m: " << m << endl;
	vector<int> output;
	int j = 1;
	int k = 1;
	int i = 1;


	while((n-k) >= m){
		cout << "Entrou no primeiro While!! " << endl;
		while( j <= m && T[i] == p[j]){
			cout << " ANTES Dentro do while :  i " << i << " j " << j << endl;
			cout << " T [i] " << T[i] << " p[j] " << p[j] << endl;
			i ++;
			j ++;
			cout << " DEPOIS Dentro do while :  i " << i << " j " << j << endl;
						cout << " T [i] " << T[i] << " p[j] " << p[j] << endl;
		}

		if(j>=m){
			output.push_back(k);
			cout << "Dentro do primeiro if" << endl;
		}
		if(prefix[j-1] > 0){
			cout << "Dentro do segundo if" << endl;
			cout << "Valor de k " << k <<endl;
			k = i - prefix[j-1];
		}else{
			if(i==k){
				i++;
				cout << "Dentbatro do terceiro if" << endl;
			}
			else
				k = i;
		}
		if(j > 1)
			j = prefix[j-1]+1;
	}

	for(int i=0 ; i < output.size() ; i++){
		cout << "para i = " << i << " ";
		cout << output[i] << "\n";
	}


}
