//
//  main.cpp
//  graphs. graph application tasks. alien alphabet
//
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "alien_alphabet.hpp"

using namespace std;

int main(int argc, const char* argv[]){
	cout << "=== Alien Alphabet from Dictionary ===" << endl;
	// vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
	vector<string> dict;
	string word;
	cout << "---> Enter words into a alien dictionary: ";
	do {
		cin >> word;
		dict.push_back(word);
	} while(cin.get() != '\n');
	cout << "---> Analizing Dictionry" << endl;
	AnalizeDictionary(dict);
}
