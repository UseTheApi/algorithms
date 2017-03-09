//
//  main.cpp
//  algorithms. Dynamic Programming. Longest Palindromic Subsequence
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "lps.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    cout << "Dynamic Programming. Longest Palindromic Subsequence." << endl;
    string s = "character";
    cout << LongestPalindromeSubsequence(s) << endl;
    return 0;
}

