#include "PrefixTree.h";

vector<char> Node::al = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ' ', ',',
						'Á', 'É', 'Í', 'Ó', 'Ú', 'á', 'é', 'í', 'ó', 'ú',
						'À', 'à', 'Ã', 'Õ', 'ã', 'õ', 'Â', 'Ê', 'Ô', 'â', 'ê', 'ô', 'ç'};


int Node::charToIndex(char c){
	for(int i = 0; i < al.size(); i++){
		if (al.at(i) == c) return i;
	}
	return -1;
}

char Node::indexToChar(int i){
	return al.at(i);
}

void Node::insert(string &s, int i){
	if (i == s.length()){
		isWord = true;
		return;
	}
	int index = charToIndex(s[i]);
	if (descendents[index] == NULL){
		descendents[index] = new Node();
	}
	descendents[index]->insert(s, i+1);
}

void Node::complete(vector<string> & result, string word, int index, string & newString){
	if (index == word.length()-1){
		if (isWord){
			result.push_back(newString);
		}
		for (unsigned i = 0; i < descendents.size(); i++){
			if (descendents[i] != NULL){
				newString += indexToChar(i);
				descendents[i]->complete(result, word, index, newString);
				newString = newString.substr(0, newString.length()-1);
			}
		}
	}
	else {
		int newIndex = charToIndex(word[index]);
		if (descendents[newIndex] == NULL){
			return;
		}
		else {
			newString += word[index];
			descendents[newIndex]->complete(result, word, index+1, newString);
		}

	}

}

Node* Node::advanceChar(vector<string> & result, char car, string& newString){
	int newIndex = charToIndex(car);
	newString += car;
	return descendents[newIndex];
}


void PrefixTree::insert(string s){
	string newWord;

	root->insert(s, 0);
}


vector<string> PrefixTree::complete(string s){
	vector<string> result;
	string w = "";
	root->complete(result, s, 0, w);

	return result;
}


vector<string> PrefixTree::completeChar(char c){
	vector<string> result;
	static Node * currNode = root;
	static string currString = "";
	if ( c == '\0'){
		currNode = root;
		currString = "";
	}
	else {
		if(currNode != NULL)
			currNode = currNode->advanceChar(result, c, currString);
		if(currNode != NULL){
			currNode->complete(result, "", -1, currString);
		}
	}
	return result;
}
