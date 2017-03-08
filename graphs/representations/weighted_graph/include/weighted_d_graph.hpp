//
//  weighted_graph.hpp
//  graph representations. weighted graph.
//
//   Created by alifar on 03/06/17.
//   Copyright © 2017 alifar. All rights reserved.
//

#include "weighted_vertex.hpp"
#include <vector>
#include <utility>

template <class T>
class WeightedDGraph{
public:
    WeightedDGraph();
    void AddEdge(T, T, int); // add Edge for 2 nodes and weight
    void AddVertex(T); // add Vertex into the Graph
    void RemoveEdge(T, T);
    bool kempty;
    std::pair<VertexW<T> *, int> get_vertex(T); // get vertex by it's value
    void display_vertices();
    void display_lists();
    std::vector<VertexW<T> *> get_vertices();
    std::vector<std::vector<std::pair<VertexW<T> *, int>>> get_adj();
    std::vector<std::pair<VertexW<T> *, int>> Neighbours(T);
private:
    std::vector<VertexW<T> *> vertices_;
    std::vector<std::vector<std::pair<VertexW<T> *, int>>> adj_;
};

template <class T>
WeightedDGraph<T>::WeightedDGraph(){
    kempty = true;
}

template <class T>
void WeightedDGraph<T>::AddVertex(T new_data){
    if(kempty){
        kempty = false;
    }
    VertexW<T> *new_vertex = new VertexW<T>(new_data);
    vertices_.push_back(new_vertex);
    std::vector<std::pair<VertexW<T> *, int>> adj_list;
    adj_list.push_back(std::make_pair(new_vertex, 0));
    adj_.push_back(adj_list);
}

template <class T>
std::vector<VertexW<T> *> WeightedDGraph<T>::get_vertices(){
    return vertices_;
}

template <class T>
std::vector<std::vector<std::pair<VertexW<T> *, int>>> WeightedDGraph<T>::get_adj(){
    return adj_;
}

template <class T>
std::pair<VertexW<T> *, int> WeightedDGraph<T>::get_vertex(T key){
    for(int i = 0; i < vertices_.size(); ++i){
        if(vertices_[i]->data == key){
            return std::make_pair(vertices_[i], i);
        }
    }
    return std::make_pair(nullptr, 0);
}

template <class T>
void WeightedDGraph<T>::AddEdge(T key1, T key2, int weight){
    std::pair<VertexW<T> *, int> vertex_p1 = get_vertex(key1);
    std::pair<VertexW<T> *, int> vertex_p2 = get_vertex(key2);
    if(!vertex_p1.first || !vertex_p2.first){
        return;
    }
    adj_[vertex_p1.second].push_back(std::make_pair(vertex_p2.first, weight));
}

template <class T>
void WeightedDGraph<T>::RemoveEdge(T key1, T key2){
    std::pair<VertexW<T> *, int> vertex_p1 = get_vertex(key1);
    std::pair<VertexW<T> *, int> vertex_p2 = get_vertex(key2);
    if(!vertex_p1.first || !vertex_p2.first){
        return;
    }
    int id1 = vertex_p1.second;
    std::vector<std::pair<VertexW<T> *, int>> a_list = adj_[id1];
    for(int i = 0; i < a_list.size(); ++i){
        if(a_list[i].first == vertex_p2.first){
            adj_[id1].erase(adj_[id1].begin()+i, adj_[id1].begin()+i+1);
        }
    }
}

template <class T>
void WeightedDGraph<T>::display_vertices(){
    for(auto it: vertices_){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template <class T>
void WeightedDGraph<T>::display_lists(){
    for(auto adj_list: adj_){
        for(auto v_pair: adj_list){
            std::cout << v_pair.first << ": " << v_pair.second << "; ";
        }
        std::cout << std::endl;
    }
}

template <class T>
std::vector<std::pair<VertexW<T> *, int>> WeightedDGraph<T>::Neighbours(T source){
    std::pair<VertexW<T> *, int> source_p = get_vertex(source);
    for(auto adj_list: adj_){
        if(adj_list[0].first == source_p.first){
            adj_list.erase(adj_list.begin());
            return adj_list;
        }
    }
    return std::vector<std::pair<VertexW<T> *, int>>();
}

