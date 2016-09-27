//
//  main.cpp
//  binomial_coefficient
//
//  Created by alifar on 9/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "binomial_coefficient.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	int n;
	int k;
	cout << "n choose k: Enter n and then k: ";
	cin >> n;
	cin >> k;
	cout << endl;

	cout << "Binomial coefficient for " << n << " choose " << k << ": "<< BimonialCoefficient(n, k) << endl;
}