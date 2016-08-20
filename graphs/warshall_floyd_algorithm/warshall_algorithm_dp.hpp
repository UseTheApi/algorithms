//
//  warshall_algorithm_dp.hpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

std::vector< std::vector<int> > transitive_closure_warshall(std::vector< std::vector<int> > &adjacency_matrix);
void print_matrix(const std::vector< std::vector<int> > &matrix);
std::vector< std::vector<int> > init_matrix(int size);
