//
//  weighted_vertex.hpp
//  graph representations. weighted graph.
//
//   Created by alifar on 03/06/17.
//   Copyright © 2017 alifar. All rights reserved.
//

#include <iostream>

template <class T>
struct VertexW{
    T data;
    int min_distance;
    int finished;
    bool visited;
    template <class V>
    friend std::ostream & operator<<(std::ostream &, const VertexW<V> *);
    VertexW(T);
    ~VertexW();
};

template <class T>
VertexW<T>::VertexW(T init_data){
    data = init_data;
    visited = false;
    finished = 0;
}

template <class V>
std::ostream & operator<<(std::ostream &os, const VertexW<V> *v){
    os << v->data;
    return os;
}

