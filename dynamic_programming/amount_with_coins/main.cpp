//
//  main.cpp
//  amount_with_coins (description is in .cpp file)
//
//  Created by alifar on 9/26/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "amount_with_coins.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	vector<int> denominations;
	int amount;

	cout << "Enter required amount: ";
	cin >> amount;

	cout << "Enter all denominations (integers): ";
	int item;
	do{
		cin >> item;
		denominations.push_back(item);
	} while(cin.get() != '\n');

	std::cout << "Result: " << WaysToGetAmount(amount, denominations) << endl;
}
