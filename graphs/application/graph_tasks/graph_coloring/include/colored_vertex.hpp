//
//  colored_vertex.hpp
//  graphs. graph application tasks. graph_coloring
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <adjacency_lists.hpp>

template <class T>
struct ColoredVertex: public Vertex<T>{
    ColoredVertex(T init_data, int init_id): Vertex<T>(init_data, init_id){
        color = -1;
    }
    int color;
};

