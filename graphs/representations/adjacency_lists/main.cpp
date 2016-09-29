//  
//   main.cpp   
//   graph representations  
//  
//   Created by alifar on 9/28/16.
//   Copyright © 2016 alifar. All rights reserved.
//

#include "adjacency_lists.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	Graph<int> *graph = new Graph<int>();
	cout << graph->add_vertex(4) << endl;
	cout << graph->add_vertex(1) << endl;
	cout << graph->add_vertex(3) << endl;

	graph->add_edge(0, 1);
	graph->add_edge(0, 2);
	graph->add_edge(1, 2);

	cout << endl;
	graph->display_lists();

	graph->remove_edge(0, 2);

	cout << endl;

	graph->display_lists();

}