//
//  lps.cpp
//  algorithms. Dynamic Programming. Longest Palindromic Subsequence
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "lps.hpp"
#include <algorithm>
#include <iostream>

int LongestPalindromeSubsequence(const std::string &str){
    int l_mat[str.size()][str.size()];
    int j; // last index in palindromic subsequence

    for(size_t i = 0; i < str.size(); ++i){
        l_mat[i][i] = 1;
    }
    for(size_t cl = 2; cl <= str.size(); ++cl){
        for(size_t i = 0; i < str.size() - cl + 1; ++i){
            j = cl + i - 1;
            if(str[i] == str[j] && cl == 2){
                l_mat[i][j] = 2;
            } else if(str[i] == str[j]){
                l_mat[i][j] = l_mat[i+1][j-1] + 2;
            } else{
                l_mat[i][j] = std::max(l_mat[i+1][j], l_mat[i][j-1]);
            }
        }
    }
    return l_mat[0][str.size()-1];
}
