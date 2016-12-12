//
//  a_shortest_path.hpp
//  graph traversals. bfs application
//
//  Created by alifar on 10/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "a_shortest_path.hpp"

using namespace std;

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

	cout << "Enter two vertex id's for finding a shortest path: ";
	int id1, id2;
	cin >> id1;
	cin >> id2;

	bfs_queue(graph, id1);

	VertexBfs<char> *v1 = graph->get_vertex_by_id(id1);
	VertexBfs<char> *v2 = graph->get_vertex_by_id(id2);

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	cout << endl;
	cout << "A Shortest Path: " << endl;

	std::vector<VertexBfs<char> *> path;

	AShortestPath(graph, v2, v1, path);

	for(auto it: path){
		cout << it << " ";
	}
	cout << endl;
}
