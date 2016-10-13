//
//  edge_classification.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

// #include <vertex_bfs.hpp>

#include <map>
#include <iostream>

enum EdgeType { kTree, kForward, kBackward, kCross };

class Test{
private:
	std::map<char, EdgeType> types_;
public:
	void add_type(char a, EdgeType type){
		types_[a] = type;
	}
	std::map<char, EdgeType> get_types(){
		return types_;
	}
};
