#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


class Node {
	static vector<char> al;

	friend class PrefixTree;
	vector <Node *> descendents;
	bool isWord;

	Node(){
		descendents.resize(al.size());
		isWord = false;
	}

	int charToIndex(char c);

	char indexToChar(int i);

	void insert(string &s, int i);

	void complete(vector<string> & result, string word, int index, string & newString);

	Node* advanceChar(vector<string> & result, char car, string& newString);

};

class PrefixTree {
	Node * root;
public:

	PrefixTree(){
		root = new Node();
	}

	void insert(string s);

	vector<string> complete(string s);

	vector<string> completeChar(char c);

};



