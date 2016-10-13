//  
//   main.cpp   
//   graph representations  
//  
//   Created by alifar on 9/28/16.
//   Copyright © 2016 alifar. All rights reserved.
//

#include "adjacency_lists.hpp"

using namespace std;

// int main(int argc, const char *argv[]){
// 	Vertex<int> *v = new Vertex<int>(4, 0);
// 	cout << v << endl;
// 	LinkedList<Vertex<int> *> list;
// 	list.push(v);
// 	for(auto it: list){
// 		cout << it << endl;
// 	}
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

	int i3, i4;
	cout << "Remove edges using Ids of the vertices (Press enter when done): ";
	do{
		cin >> i3;
		cin >> i4;
		graph->remove_edge(i3, i4);
	} while(cin.get() != '\n');

	cout << endl;
	cout << "Adjacency Lists for the graph: " << endl;
	graph->display_lists();
	cout << endl;

	return 0;
}
