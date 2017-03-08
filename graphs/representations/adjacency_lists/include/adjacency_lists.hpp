//
//  adjacency_lists.hpp
//  graph representations
//
//  Created by alifar on 9/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "vertex.hpp"
#include <linked_list.hpp>
#include <vector>
#include <iostream>

/*
 Graph representations:
    Array of Adjacency List for each vertex for unweighted (un-)directed graph
    a -- b
    |    |
    c    d

    a -> b -> c
    b -> a -> d
    c -> a
    d -> b
*/

template <class T, template<class> class Node>
class Graph{
public:
    Graph();
    Graph(bool);
    bool directed; // true if Directed
    int add_vertex(T); // returns an id of the vertex (position in vertices[])
    void add_edge(int, int); // positions (ids) of vertices
    void remove_edge(int, int);
    LinkedList<Node<T> *> neighbours(int); // adjacent vertices for a given vertex id
    void display_lists();
    void display_vertices();
    std::vector<Node<T> *> get_vertices();
    std::vector<LinkedList<Node<T> *>> get_adj();
    Node<T> * get_vertex_by_id(int);
    Node<T> * get_vertex_by_value(T);
    bool empty;
private:
    std::vector<Node<T> *> vertices_;
    std::vector<LinkedList<Node<T> *>> adj_;
};

template <class T, template <class> class Node>
Graph<T, Node>::Graph(){
    directed=false;
    empty=true;
}

template <class T, template<class> class Node>
Graph<T, Node>::Graph(bool graph_type){
    directed = graph_type;
    empty = true;
}

template <class T, template<class> class Node>
int Graph<T, Node>::add_vertex(T new_data){
    empty = false;
    Node<T> *new_vertex = new Node<T>(new_data, vertices_.size());
    vertices_.push_back(new_vertex);
    LinkedList<Node<T> *> adj_list;
    adj_list.push(new_vertex);
    adj_.push_back(adj_list);
    return new_vertex->get_id();
}

template <class T, template<class> class Node>
Node<T> * Graph<T, Node>::get_vertex_by_id(int given_id){
    for(auto it: vertices_){
        if(it->get_id() == given_id){
            return it;
        }
    }
    return 0;
}

template <class T, template<class> class Node>
Node<T> * Graph<T, Node>::get_vertex_by_value(T given_value){
    // std::vector<Node<T> *> vertices =
    for(auto it: vertices_){
        if(it->get_data() == given_value){
            return it;
        }
    }
    return 0;
}

template <class T, template<class> class Node>
void Graph<T, Node>::add_edge(int index1, int index2){
    Node<T> *v1 = get_vertex_by_id(index1);
    Node<T> *v2 = get_vertex_by_id(index2);
    if(v1 != 0 && v2 != 0){
        adj_[index1].append(v2);

        if(!directed){
            adj_[index2].append(v1); // indexes are used as ids for vertices. it is to simplify implementation
        }
    }
}

template <class T, template<class> class Node>
void Graph<T, Node>::remove_edge(int index1, int index2){
    Node<T> *v1 = get_vertex_by_id(index1);
    Node<T> *v2 = get_vertex_by_id(index2);
    if(v1 != 0 && v2 != 0){
        adj_[index1].remove(v2);

        if(!directed){
            adj_[index2].remove(v1);
        }
    }
}

template <class T, template<class> class Node>
LinkedList<Node<T> *> Graph<T, Node>::neighbours(int index){
    if(index >= vertices_.size()){
        return 0;
    }

    LinkedList<Node<T> *> list = adj_[index];
    list.remove_head();
    return list;

}

template <class T, template<class> class Node>
void Graph<T, Node>::display_lists(){
    for(auto it: adj_){
        it.print_list();
        std::cout << std::endl;
    }
}

template <class T, template<class> class Node>
void Graph<T, Node>::display_vertices(){
    for(auto it: vertices_){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template <class T, template<class> class Node>
std::vector<Node<T> *> Graph<T, Node>::get_vertices(){
    return vertices_;
}

template <class T, template<class> class Node>
std::vector<LinkedList<Node<T> *>> Graph<T, Node>::get_adj(){
    return adj_;
}
