/*
 * StringMatching.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "StringMatching.h"

using namespace std;

int prefix[8];

void KnuthMorrisPratt(vector<string> moradas, string cadeia){

	for(int i = 0; i < moradas.size(); i++){

	}

}

void prefixFunction(string c){

	prefix[0] = 0;
	int a = 0;

	for(int b = 1; b < 8; b++){

		while(a>0 && c[a] != c[b]){
			a = prefix[a];
		}

		if(c[a] == c[b]){
			a +=1;
		}

		prefix[b] = a ;
	}

	for(unsigned int i = 0 ; i < c.length() ; i++){
			cout << prefix[i] << "\n";
	}

}

void stringMatching(string morada, string c){
	prefixFunction(c);

	string T = "cozacocacolacococacola" ; //frase a ser testada
	int n = T.length();
	int m = c.length();

	cout << "n: " << n << " m: " << m << endl;
	vector<int> output;
	int j = 1;
	int k = 1;
	int i = 1;


	while((n-k) >= m){
		cout << "Entrou no primeiro While!! " << endl;
		while( j <= m && T[i] == c[j]){
			cout << " ANTES Dentro do while :  i " << i << " j " << j << endl;
			cout << " T [i] " << T[i] << " p[j] " << c[j] << endl;
			i ++;
			j ++;
			cout << " DEPOIS Dentro do while :  i " << i << " j " << j << endl;
						cout << " T [i] " << T[i] << " p[j] " << c[j] << endl;
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

	for(unsigned int i = 0 ; i < output.size() ; i++){
		cout << "para i = " << i << " ";
		cout << output[i] << "\n";
	}


}
