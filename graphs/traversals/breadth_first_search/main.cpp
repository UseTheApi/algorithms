//
//  main.cpp
//  graph traversals
//
//  Created by alifar on 9/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "bfs.hpp"
// #include "vertex_bfs.hpp"
#include <iostream>

using namespace std;

// int main(int argc, const char *argv[]){
// 	VertexBfs<int> *v = new VertexBfs<int>(5, 1);
// 	cout << v->get_data() << endl;
// 	return 0;
// }

int main(int argc, const char *argv[]){
	bool g_type = false; // true if Graph is Directed
	char input;
	cout << "Type of graph? [default: Undirected, 1 for Directed]: ";
	if(cin.get() != '\n'){
		g_type = true;
	} 

	cout << endl;

	Graph<char, VertexBfs> *graph = new Graph<char, VertexBfs>(g_type);
	char item;

	cout << "Add vertices to the Graph: ";
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

	cout << "Enter vertex id for BFS start: ";
	int bfs_start_id;
	cin >> bfs_start_id;

	cout << "BFS using map: ";
	bfs_map<>(graph, bfs_start_id);
	cout << endl;
	cout << "BFS using queue and vertex attributes: ";
	bfs_queue<>(graph, bfs_start_id);
	cout << endl;
}
