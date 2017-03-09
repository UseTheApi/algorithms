//
//  traveling_salesman.hpp
//  graphs. graph application tasks. traveling salesman
//
//  Created by alifar on 03/10/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <weighted_graph.hpp>
#include <iostream>
#include <climits>
#include <algorithm>

template <class T>
using vertex_vector = std::vector<VertexW<T> *>;

template <class T>
void swap(VertexW<T> *v1, VertexW<T> *v2){
    VertexW<T> tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

template <class T>
int calculate_path_weight(WeightedGraph<T> graph, vertex_vector<T> vertices){
    for(auto it: vertices){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    graph.display_lists(); 
    std::cout << std::endl;
    int i = 0;
    int route_weight = 0;
    int cur_w = 0;
    while(i != vertices.size()-1){
        cur_w = graph.EdgeWeight(vertices[i], vertices[i+1]);
        std::cout << "CUR_W: " << cur_w << " ";
        route_weight+=cur_w;
        ++i;
    }
    route_weight += graph.EdgeWeight(vertices[vertices.size()-1], vertices[0]);
    std::cout << std::endl;
    //std::cout << route_weight << std::endl;
    return route_weight;
}

template <class T>
int ts_naive_helper(WeightedGraph<T> &graph, vertex_vector<T> vertices, int min_weight_route, int start, int end){
    if(start == end){
        int cur_route_w = calculate_path_weight(graph, vertices);
        min_weight_route = std::min(min_weight_route, cur_route_w);
    }
    for(int i = start; i <= end; ++i){
        swap(vertices[start], vertices[i]);
        ts_naive_helper<T>(graph, vertices, min_weight_route, start+1, end);
        swap(vertices[start], vertices[i]);
    }
    return min_weight_route;
}

template <class T>
int TravelingSalesmanNaive(WeightedGraph<T> &graph){
    int resulting_min_weight = INT_MAX;
    vertex_vector<T> vertices = graph.get_vertices();
    resulting_min_weight = ts_naive_helper<T>(graph, vertices, resulting_min_weight, 0, vertices.size()-1);
    return resulting_min_weight;
}

