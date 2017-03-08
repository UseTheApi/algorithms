//
//  weighted_vertex.hpp
//  graph representations. weighted graph.
//
//   Created by alifar on 03/06/17.
//   Copyright © 2017 alifar. All rights reserved.
//

#include <iostream>
#include <climits>

template <class T>
struct VertexW{
    T data;
    int min_distance;
    int finished;
    bool visited;
    VertexW(T);
    ~VertexW();
};

template <class T>
VertexW<T>::VertexW(T init_data){
    data = init_data;
    visited = false;
    finished = 0;
    min_distance = INT_MAX;
}

template <class V>
std::ostream & operator<<(std::ostream &os, const VertexW<V> *v){
    os << v->data;
    return os;
}

template <class V>
bool operator==(VertexW<V> *v1, VertexW<V> *v2){
    return v1->data == v2->data;
}

template <class V>
bool operator<(VertexW<V> *v1, VertexW<V> *v2){
    return v1->data < v2->data;
}

template <class V>
bool operator>(VertexW<V> *v1, VertexW<V> *v2){
    return v1->data > v2->data;
}

