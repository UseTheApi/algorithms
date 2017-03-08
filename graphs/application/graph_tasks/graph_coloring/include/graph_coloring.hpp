//
//  graph_coloring.hpp
//  graphs. graph application tasks. graph_coloring
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "colored_vertex.hpp"
#include <iostream>

template <class T>
void DisplayColors(Graph<T, ColoredVertex> graph){
    for(auto it: graph.get_vertices()){
        std::cout << it << ": " << it->color << "; ";
    }
    std::cout << std::endl;
}

template <class T>
void GreedyColoring(Graph<T, ColoredVertex> &graph){
    graph.get_vertices()[0]->color = 0;
    std::vector<bool> available_colors(graph.get_vertices().size());
    // initializing all colors as available
    for(auto it: available_colors){
        it = true;
    }
    // marking colors of adjacent vertices as unavailable
    for(int i = 1; i < graph.get_vertices().size(); ++i){
        ColoredVertex<T> *cur_v = graph.get_vertex_by_id(i);
        for(auto it: graph.neighbours(i)){
            if(it->color != -1){
                available_colors[it->color] = false;
            }
        }
        for(auto it: available_colors){
            std::cout << it << " ";
        }
        std::cout << std::endl;
        // searching for available color to assign to current vertex
        for(int i = 0; i < available_colors.size(); ++i){
            if(available_colors[i]){
                cur_v->color = i;
                break;
            }
        }
        // marking all colors as available for next cycle
        for(auto it: available_colors){
            it = true;
        }
    }
    DisplayColors(graph);
}

