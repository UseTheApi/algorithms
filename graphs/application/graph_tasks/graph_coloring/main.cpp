//
//  main.cpp
//  graphs. graph application tasks. graph coloring
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "graph_coloring.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    bool g_type = false; // true if Graph is Directed
    char input;
    cout << "Type of graph? [default: Undirected, 1 for Directed]: ";
    if(cin.get() != '\n'){
        g_type = true;
    } 

    cout << endl;

    Graph<char, ColoredVertex> graph;
    graph.directed = g_type;
    char item;

    cout << "Add vertices to the Graph (type - char): ";
    do{
        cin >> item;
        cout << "Id of item " << item << ": " << graph.add_vertex(item) << endl;
    } while(cin.get() != '\n');
    graph.display_vertices();
    cout << endl;

    cout << "Add edges to the graph using Ids of the vertices (Press enter when done): ";
    int i1, i2;
    do{
        cin >> i1;
        cin >> i2;
        graph.add_edge(i1, i2);
    } while(cin.get() != '\n');

    cout << endl;
    cout << "Adjacency Lists for the graph: " << endl;
    graph.display_lists();
    cout << endl;

    cout << "Greedy Coloring of the Graph:" << endl;
    GreedyColoring(graph);
    return 0;
}

