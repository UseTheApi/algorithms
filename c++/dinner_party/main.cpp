//
//  main.cpp
//  algorithms. dinner_party
//
//  Created by alifar on 01/26/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "dinner_party.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "==== Dinner Party ====" << endl;
	vector<char> friends;
	char item;
	cout << "--> Enter friends as chars: ";
	do{
		cin >> item;
		friends.push_back(item);
	} while(cin.get() != '\n');
	cout << "--> Calculated friends parties: ";
	vector<string> groups = DinnerParties(friends, 3);

	for(auto it: groups){
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
