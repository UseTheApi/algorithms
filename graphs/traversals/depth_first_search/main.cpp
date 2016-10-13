//
//  main.cpp
//  graph traversals. dfs
//
//  Created by alifar on 10/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "dfs.hpp"
#include <iostream>
#include <map>

/*
 DFS has many application in Graph Theory. With DFS we can solve tasks like:
 	* detecting a cycle in a graph
 	* topological sort
 	* edge classification

 	and many more (some are represented in this project).

 DFS search idea is to visit all vertices of the graph in depth approach.

 Recursion is very great to use here: in current adjacency list (of a 'root_vertex') explore recursively each vertex

 DFS_visit() is a recusion part of the search

 DFS itself helps to visit all vertices of the graph that might unreachable from the first given vertex (ex.: Directed graph or Disconnected graph) 
*/

using namespace std;

int main(int argc, const char *argv[]){
	bool g_type = false; // true if Graph is Directed
	char input;
	cout << "Type of graph? [default: Undirected, 1 for Directed]: ";
	if(cin.get() != '\n'){
		g_type = true;
	}

	cout << endl;

	Graph<char, Vertex> *graph = new Graph<char, Vertex>(g_type);
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

	map<Vertex<char> *, Vertex<char> *> dfs_map = dfs<>(graph); // dfs_map represents tree edges of the graph
	cout << endl;
}
