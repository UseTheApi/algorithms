//
//  main.cpp
//  algorithms. determing a cycle
//
//  Created by alifar on 12/19/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "max_burglary.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
	const std::vector<int> arr = {2, 3, 4, 1, 1, 7};

	int res = MaxProfit(arr);
	cout << res << endl;
}
