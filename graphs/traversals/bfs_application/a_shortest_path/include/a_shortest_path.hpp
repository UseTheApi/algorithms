//
//  a_shortest_path.hpp
//  graph traversals. bfs application
//
//  Created by alifar on 10/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <bfs.hpp>
#include <iostream>

/*
 Finding a(!) shortest path. 

 BFS can give us one of many (if any) possible paths from vertex1 to vertex2

 Assuming that 'bfs_queue' function  had already processed give Graph written function will just walk through
 the vertices using parent pointer, if parent = 0 then there is no path from v1 to v2
*/

template <class T>
void a_shortest_path(Graph<T, VertexBfs> *graph, VertexBfs<T> *v1, VertexBfs<T> *v2, std::vector<VertexBfs<T> *> &path){
	if(!v1 || !v2){
		return;
	}
	if(v1 == v2){
		// std::cout << v1 << " ";
		return;
	} else if(!v1->get_parent()){
		path.clear();
		return;
	} else{
		v1 = v1->get_parent();
		a_shortest_path(graph, v1, v2, path);
		path.push_back(v1);
	}
}
