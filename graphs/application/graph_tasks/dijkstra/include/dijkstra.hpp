//
//  dijkstra.hpp
//  graphs. graph application tasks. dijkstra algorithm implementation
//
//  Created by alifar on 03/05/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <weighted_graph.hpp>
#include <queue>
#include <iostream>

template <class T>
struct GreaterThenByPriority
{
  bool operator()(const VertexW<T>* lhs, const VertexW<T>* rhs) const
  {
    return lhs->min_distance > rhs->min_distance;
  }
};

template <class T>
using PriorityQueue = std::priority_queue<VertexW<T> *, std::vector<VertexW<T>*>, GreaterThenByPriority<T>>;

template <class T>
void InitializeQueue(PriorityQueue<T> &q, WeightedGraph<T> &graph, T source){
    std::pair<VertexW<T> *, int> source_pair= graph.get_vertex(source);
    source_pair.first->min_distance = 0;
    for(auto it: graph.get_vertices()){
        if(it->data != source){
            it->min_distance = INT_MAX;
        } else{
            it->min_distance = 0;
        }
        std::cout << it << " " << it->min_distance << std::endl;
        q.push(it);
    }
}

template <class T>
void DisplayMinWeights(WeightedGraph<T> &graph){
    std::cout << "Min Weights for Vertices: " << std::endl;
    for(auto it: graph.get_vertices()){
        std::cout << it << ": " << it->min_distance << "; ";
    }
}

template <class T>
void ShortestPathsDijkstra(WeightedGraph<T> &graph, T source){
    PriorityQueue<T> q;
    InitializeQueue(q, graph, source);
    while(!q.empty()){
        VertexW<T> *cur_v = q.top();
        q.pop();
        std::vector<std::pair<VertexW<T> *, int>> cur_neighbours = graph.Neighbours(cur_v->data);
        for(auto it: graph.Neighbours(cur_v->data)){
            if(it.first->min_distance > it.second + cur_v->min_distance){
                it.first->min_distance = it.second + cur_v->min_distance;
            }
        }
    }
    DisplayMinWeights(graph);
    return;
}

