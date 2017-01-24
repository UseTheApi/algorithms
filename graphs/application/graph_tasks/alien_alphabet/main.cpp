//
//  main.cpp
//  graphs. graph application tasks. alien alphabet
//
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <topological_sort.hpp>
#include "add_to_graph.hpp"
#include "alien_alphabet.hpp"
#include "solution_with_topo_sort_implemented.hpp"

using namespace std;

int main(int argc, const char* argv[]){
	cout << "=== Alien Alphabet from Dictionary ===" << endl;
	//vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
	vector<string> dict;
	string word;
	cout << "---> Enter words into a alien dictionary: ";
	do {
		cin >> word;
		dict.push_back(word);
	} while(cin.get() != '\n');
	cout << "---> Analizing Dictionry using existing topological sort:" << endl;
	CalculateAlphabet(dict);
	cout << "---> Analizing Dictionry with own topological sort:" << endl;
	std::vector<char> result = ComputeAlphabet(dict);
	for(auto it: result){
		cout << it << " ";
	}
	cout << endl;
}
