//
//  main.cpp
//  stairs_hopper (decription is in .cpp file)
//
//  Created by alifar on 9/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "hop_some_stairs.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	int stairs_num;
	cout << "Enter a number of stairs to hop: ";
	cin >> stairs_num;

	cout << "Number of different ways to hop: " << WalkThroughStairs(stairs_num) << endl;
}
