//
//  main.cpp
//  graphs. graph application tasks.dijkstra 
//
//  Created by alifar on 03/05/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "dijkstra.hpp"

using namespace std;

int main(int argc, const char *argv[]){
    cout << endl;
    cout << "Graph Shortest Paths: Weighted Graph." << endl;
    WeightedGraph<char> graph;
    cout << "Add vertices to the Graph (type - char): ";
    char item;

    do{
        cin >> item;
        graph.AddVertex(item);
    } while(cin.get() != '\n');

    cout << "Add edges to the graph by entering vertex data and integer weight (Press enter when done): " << endl;
    int weight;
    char v1, v2;
    do{
        cin >> v1;
        cin >> v2;
        cin >> weight;
        graph.AddEdge(v1, v2, weight);
    } while(cin.get() != '\n');
    cout << endl;
    cout << "Adjacency Lists for the graph: " << endl;
    graph.display_lists();
    cout << endl;
    cout << "Enter a Source vertex for Dijkstra: ";
    char source_item;
    cin >> source_item;
    ShortestPathsDijkstra(graph, source_item);
    cout << endl;
    return 0;
}

