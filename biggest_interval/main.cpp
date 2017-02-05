//
//  main.cpp
//  algorithms. biggest inclusive interval
//
//  Created by alifar on 02/05/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "biggest_interval.hpp"
#include <iostream>

using namespace std;

/*
 Find the Biggest Inclusive Interval from a list of given tuples. (source: Glassdoor)
*/

int main(int args, const char *argv[]){
	cout << "==== The Biggest Inclusive Interval ====" << endl;

	pair<int, int> p;
	vector<pair<int, int>> v;
	int f, s;

	cout << "Enter pairs and hit enter: ";

	do {
		cin >> f;
		cin >> s;
		p.first = f;
		p.second = s;
		v.push_back(p);
	} while(cin.get() != '\n');

		// 	cout << it.first << " " << it.second << endl;
	// }
	cout << "Calculating the biggest inclusive interval: " << endl;

	pair<int, int> res = CalculateInterval(v);
	cout << res.first << " " << res.second << endl;

	return 0;
}
