/*
 * StringMatching.cpp
 *
 *  Created on: 28/05/2015
 *      Author: Filipa
 */

#include "StringMatching.h"

using namespace std;

void KnuthMorrisPratt(string morada){
	for(int i = 0; i < morada.length(); i++){

	}
}

void prefixFunction(){

	string p = "cocacola";
	int prefix[8];

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

