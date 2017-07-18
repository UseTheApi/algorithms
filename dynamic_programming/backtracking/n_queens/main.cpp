//
//  main.cpp
//  algorithms. Dynamic Programming. Backtracking. N Queens
//
//  Created by alifar on 07/18/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "n_queens.hpp"

using namespace std;

int main(int argc, const char *argv[]){
    vector<pair<int, int>> pos = solve_n_queens(4);
    for (auto it: pos){
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
