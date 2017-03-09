//
//  main.cpp
//  graphs. graph application tasks. traveling salesman
//
//  Created by alifar on 03/10/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "traveling_salesman.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    cout << "Traveling Salesman Problem : Weighted Undirected Graph." << endl;
    WeightedGraph<char> graph;
    graph.kdirected = false; // graph is undirected
    cout << "Add vertices to the Graph (type - char): ";
    char item;

    do{
        cin >> item;
        graph.AddVertex(item);
    } while(cin.get() != '\n');

    int i = 0;
    std::vector<VertexW<char> *> vertices = graph.get_vertices();
    int weight;
    while(i != vertices.size()-1){
        for(int j = i+1; j < vertices.size(); ++j){
            cout << "Enter weight for: " << vertices[i]->data << " " << vertices[j]->data << ": ";
            cin >> weight;
            graph.AddEdge(vertices[i], vertices[j], weight);
        }
        ++i;
    }
    cout << endl;
    cout << "Adjacency Lists for the graph: " << endl;
    graph.display_lists();
    cout << endl;
    cout << "Calculated minimal Path using Premutation Approach: " << endl;
    int min_w = TravelingSalesmanNaive<char>(graph);
    std::cout << std::endl;
    std::cout << "Minimum: " << min_w << std::endl;
    return 0;
}

