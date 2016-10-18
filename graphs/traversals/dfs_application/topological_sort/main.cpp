//
//  main.cpp
//  graphs. dfs application. topological sort
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "topological_sort.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Topological Sort for Directed Graph" << endl;
	Graph<char, VertexEc> *graph = new Graph<char, VertexEc>(true); // task works with Directed Graphs
	char item;

	cout << "Add vertices to the Graph (type - char): ";
	do{
		cin >> item;
		cout << "Id of item " << item << ": " << graph->add_vertex(item) << endl;
	} while(cin.get() != '\n');
	graph->display_vertices();

	cout << "Add edges to the graph using Ids of the vertices (Press enter when done): ";
	int i1, i2;
	do{
		cin >> i1;
		cin >> i2;
		graph->add_edge(i1, i2);
	} while(cin.get() != '\n');

	cout << endl;
	cout << "Adjacency Lists for the graph: " << endl;
	graph->display_lists();
	cout << endl;

	std::vector<VertexEc<char> *> sorted_result = TopologicalSort(graph);

	cout << "Topologically sorted Vertices: " << endl;
	for(auto it: sorted_result){
		cout << it << " ";
	}
	cout << endl;
	
	return 0;
}
