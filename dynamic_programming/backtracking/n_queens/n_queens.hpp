//
//  n_queens.cpp
//  algorithms. Dynamic Programming. Backtracking. N_Queens
//
//  The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
//  The expected output is a binary matrix which has 1s for the blocks where queens are placed.
//  For example following is the output matrix for above 4 queen solution.
//
//              { 0,  1,  0,  0}
//              { 0,  0,  0,  1}
//              { 1,  0,  0,  0}
//              { 0,  0,  1,  0}
//
//  Created by alifar on 07/18/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;


bool is_safe(vector<pair<int, int>> &positions, int raw, int col){
    for (int queen = 0; queen < raw; ++queen){
        pair<int, int> cur_pos = positions[queen];
        if (cur_pos.second == col || cur_pos.first + cur_pos.second == raw + col ||
                cur_pos.first - cur_pos.second == raw - col){
            return false;
        }
    }
    return true;
}


bool place_n_queens(vector<pair<int, int>> &positions, int raw, int n){
    if (raw == n){
        return true;
    }
    for (int col = 0; col < n; ++col){
        if (is_safe(positions, raw, col)){
            positions[raw] = make_pair(raw, col);
            if (place_n_queens(positions, raw+1, n)){
                return true;
            }
        }
    }
    return false;
}


vector<pair<int, int>> solve_n_queens(int n){
    vector<pair<int, int>> positions(n);
    place_n_queens(positions, 0, n);
    return positions;
}

