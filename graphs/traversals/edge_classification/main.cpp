//
//  main.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
// #include <adjacency_lists.hpp>
#include "ec_vertex.hpp"
#include <map>

using namespace std;

/*
 Edge Classification task is a classical appication of DFS in graphs.

 4 types of Edges:
 	1. Tree edges: Parent structure represent all tree edges (edges that lead to unvisited node)
 	2. Forward edges: Edges go from a vertex to descended (in tree/forest)
 	3. Backward edges: Edges go from a vertex to ancestor (in tree/forest)
 	4. Cros edges: All other edges (non-ancestor related subtrees or nodes)
*/


int main(int argc, const char *argv[]){
	Test test;
	EdgeType t1 = kTree;
	EdgeType t2 = kForward;
	test.add_type('a', t1);
	test.add_type('b', t2);
	map<char, EdgeType> v = test.get_types();

	for(auto it: v){
		cout << it.first << ": " << it.second << endl;
	}
	return 0;
}
