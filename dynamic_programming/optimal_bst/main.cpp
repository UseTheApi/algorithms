//
//  main.cpp
//  algorithms. Dynamic Programming. Optimal BST 
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "optimal_bst.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    std::vector<int> k {10, 12, 20};
    std::vector<int> w {34, 8, 50};
    int res = OptimalBst(k, w);
    cout << res << endl;
    return 0;
}
