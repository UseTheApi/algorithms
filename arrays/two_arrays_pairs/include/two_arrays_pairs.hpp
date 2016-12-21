//
//  two_arrays_pairs.hpp
//  algorithms. two_arrays_pairs
//
//  Created by alifar on 12/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef two_arrays_pairs_hpp
#define two_arrays_pairs_hpp

#include <stdio.h>
#include <vector>

int PairsBruteForce(const std::vector<int> &, const std::vector<int> &, int);
int PairsDP(const std::vector<int> &, const std::vector<int> &, int);
void print_matrix(std::vector< std::vector<int> > &);

#endif /* two_arrays_pairs_hpp */
