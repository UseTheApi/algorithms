//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "permutations.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	string str = "abc";
	cout << "--> Given String: "<< str << endl;
	permute_with_duplicates(str, 0, 2);
}