//
//  main.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "edge_classification.hpp"
#include <iostream>

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
	bool g_type = false; // true if Graph is Directed
	char input;
	cout << "Type of graph? [default: Undirected, 1 for Directed]: ";
	if(cin.get() != '\n'){
		g_type = true;
	} 

	cout << endl;

	Graph<char, VertexEc> *graph = new Graph<char, VertexEc>(g_type);
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

	cout << "Edge Classification Depth First Search" << endl;
	dfs_ec<>(graph);
	EdgeClassification(graph);
	return 0;
}
