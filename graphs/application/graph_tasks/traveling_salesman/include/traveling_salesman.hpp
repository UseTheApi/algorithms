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
void swap(T &item1, T &item2){
    T tmp = item1;
    item1 = item2;
    item2 = tmp;
}

template <class T>
int calculate_path_weight(WeightedGraph<T> graph, std::vector<T> v_collection){
    std::cout << std::endl;
    for(auto it: v_collection){
        std::cout << it << " ";
    }
    int i = 0;
    int route_weight = 0;
    int cur_w = 0;
    while(i != v_collection.size()-1){
        cur_w = graph.EdgeWeight(v_collection[i], v_collection[i+1]);
        route_weight+=cur_w;
        ++i;
    }
    route_weight += graph.EdgeWeight(v_collection[v_collection.size()-1], v_collection[0]);
    std::cout << ": " << route_weight;
    return route_weight;
}

template <class T>
int ts_naive_helper(WeightedGraph<T> &graph, std::vector<T> v_collection, int min_weight_route, int start, int end){
    if(start == end){
        int cur_route_w = calculate_path_weight(graph, v_collection);
        min_weight_route = std::min(min_weight_route, cur_route_w);
        return min_weight_route;
    }
    for(int i = start; i <= end; ++i){
        swap(v_collection[start], v_collection[i]);
        min_weight_route = std::min(min_weight_route, ts_naive_helper<T>(graph, v_collection, min_weight_route, start+1, end));
        swap(v_collection[start], v_collection[i]);
    }
    return min_weight_route;
}

template <class T>
int TravelingSalesmanNaive(WeightedGraph<T> &graph){
    int resulting_min_weight = INT_MAX;
    std::vector<T> v_collection;
    for(auto it: graph.get_vertices()){
        v_collection.push_back(it->data);
    }
    resulting_min_weight = ts_naive_helper<T>(graph, v_collection, resulting_min_weight, 0, v_collection.size()-1);
    return resulting_min_weight;
}

