//
//  main.cpp
//  algorithms. strings. unpack_string
//
//  Created by alifar on 10/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "unpack_string.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Unpack a string" << endl;
	string str;
	cout << "Enter a string: ";
	cin >> str;
	string result = UnpackString(str);
	cout << "Unpacked string: " << result << endl;
	return 0;
}