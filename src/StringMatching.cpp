/*
 * StringMatching.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "StringMatching.h"

using namespace std;

void KnuthMorrisPratt(vector<string> moradas, string cadeia){

	string output;
	for(unsigned int i = 0; i < moradas.size(); i++){
		output = stringMatching(moradas[i], cadeia);
		cout << "output: " << output << endl;
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

string stringMatching(string morada, string c){

	vector<int> prefix = prefixFunction(c);
	cout << "prefix called" << endl;

	int n = morada.length();
	int m = c.length();

	cout << "n: " << n << " m: " << m << endl;
	vector<int> output;

	int j = 0; // contador para o prefix
	int k = 0; // inicio das correspondencias
	int i = 0; // contador da frase


	while((n-k) >= m){
		while( j <= m && morada[i] == c[j]){
			i ++;
			j ++;
		}

		if(j > m){
			return morada;
		}
		if(prefix[j-1] > 0){
			k = i - prefix[j-1];
		}
		else if(i == k){
				i++;
				k = i;
		}
		if(j > 1)
			j = prefix[j-1]+1;
	}

	cout << "no match!" << endl;

}
