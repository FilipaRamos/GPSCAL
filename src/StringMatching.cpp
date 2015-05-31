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
		if(stringMatching(moradas[i], cadeia))
			cout << moradas[i] << endl;
	}

}

void prefixFunction(string c, int prefix[]){

	int m = c.length(), k;
	prefix[0] = -1;
	for (int i = 1; i < m; i++) {
		k = prefix[i - 1];
		while (k >= 0) {
			if (c[k] == c[i - 1])
				break;
			else
				k = prefix[k];
		}
		prefix[i] = k + 1;
	}
}

int stringMatching(string morada, string c){

	 int m = c.length();
	    int n = morada.length();
	    int f[m];
	    prefixFunction(c, f);
	    int i = 0;
	    int k = 0;
	    while (i < n)
	    {
	        if (k == -1)
	        {
	            i++;
	            k = 0;
	        }
	        else if (morada[i] == c[k])
	        {
	            i++;
	            k++;
	            if (k == m)
	                return 1;
	        }
	        else
	            k = f[k];
	    }
	    return 0;
}
