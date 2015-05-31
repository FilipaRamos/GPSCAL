/*
 * StringMatching.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "StringMatching.h"

using namespace std;

void KnuthMorrisPratt(vector<string> moradas, string cadeia){

	for(int i = 0; i < moradas.size(); i++){
		stringMatching(moradas[i], cadeia);
	}

}

vector<int> prefixFunction(string c){

	// VARIÁVEIS
	vector<int> prefix;
	int a = 0;

	prefix.push_back(0);

	for(unsigned int b = 1; b < c.length(); b++){

		while(a>0 && c[a] != c[b]){
			a = prefix[a];
		}

		if(c[a] == c[b]){
			a++;
		}

		prefix[b] = a ;
	}

	for(unsigned int i = 0 ; i < c.length() ; i++){
			cout << prefix[i] << "\n";
	}

	return prefix;

}

bool stringMatching(string morada, string c){

	vector<int> prefix = prefixFunction(c);

	int n = morada.length();
	int m = c.length();

	cout << "n: " << n << " m: " << m << endl;
	vector<int> output;

	int j = 0; // contador para o prefix
	int k = 0; // inicio das correspondencias
	int i = 0; // contador da frase


	while((n-k) >= m){
		//cout << "Entrou no primeiro While!! " << endl;
		while( j <= m && morada[i] == c[j]){
			//cout << " ANTES Dentro do while :  i " << i << " j " << j << endl;
			//cout << " T [i] " << T[i] << " p[j] " << c[j] << endl;
			i ++;
			j ++;
			//cout << " DEPOIS Dentro do while :  i " << i << " j " << j << endl;
			//cout << " T [i] " << T[i] << " p[j] " << c[j] << endl;
		}

		if(j > m){
			return true;
			//cout << "Dentro do primeiro if" << endl;
		}
		if(prefix[j-1] > 0){
			//cout << "Dentro do segundo if" << endl;
			//cout << "Valor de k " << k <<endl;
			k = i - prefix[j-1];
		}
		else if(i == k){
				i++;
				//cout << "Dentbatro do terceiro if" << endl;
				k = i;
		}
		if(j > 1)
			j = prefix[j-1]+1;
	}

	return false;
}
