//
//  weighted_k_tree.hpp
//  algorithms. weighted k-ary tree implementation.
//
//  Created by alifar on 02/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <set>

template <class N>
struct KWNode{
    N data;
    int weight;
    KWNode<N> *f_child;
    KWNode<N> *sibling;
    KWNode<N> *parent;
    KWNode(N, int);
    void AddSibling(KWNode<N> *);
    template <class TN>
    friend std::ostream & operator<< (std::ostream &, KWNode<TN> *);
    ~KWNode();
};

template <class N>
KWNode<N>::KWNode(N init_data, int init_weight){
    data = init_data;
    weight = init_weight;
    f_child = nullptr;
    sibling = nullptr;
    parent = nullptr;
}

template <class TN>
std::ostream & operator<< (std::ostream & os, KWNode<TN> *node){
    os << node->data;
    return os;
}

template <class N>
void KWNode<N>::AddSibling(KWNode<N> *node){
    if(!sibling){
        sibling = node;
        return;
    } else{
        KWNode<N> *cur = sibling;
        KWNode<N> *tmp = cur;
        while(cur){
            tmp = cur;
            cur = cur->sibling;
        }
        tmp->sibling = node;
    }
}

template <class T>
class WeightedKTree{
public:
    WeightedKTree();
    void Insert(T, int, KWNode<T>*);
    KWNode<T> * Search(T);
    KWNode<T> * get_root();
    void Traverse();
private:
    KWNode<T> *root_;
};

template <class T>
WeightedKTree<T>::WeightedKTree(){
    root_ = nullptr;
}

template <class T>
KWNode<T> * WeightedKTree<T>::get_root(){
    return root_;
}

template <class T>
void WeightedKTree<T>::Insert(T new_data, int new_weight, KWNode<T> *p_node){
    if(!root_){
        root_ = new KWNode<T>(new_data, 0);
        return;
    }
    if(!p_node){
    	std::cout << "Parent node not found" << std::endl;
    }
    KWNode<T> *new_node = new KWNode<T>(new_data, new_weight);
    new_node->parent = p_node;
    if(!p_node->f_child){
        p_node->f_child = new_node;
    } else{
        p_node->f_child->AddSibling(new_node);
    }
}

template <class T>
KWNode<T> * WeightedKTree<T>::Search(T key){
    if(!root_){
        return nullptr;
    }
    KWNode<T> *cur = root_;
    std::set<KWNode<T> *> visited;
    while(cur && cur->data != key){
        if(visited.find(cur) != visited.end()){
            cur = cur->sibling ? cur->sibling : cur->parent;
        } else{
            visited.insert(cur);
            if(cur->f_child){
                cur = cur->f_child;
            } else if(cur->sibling){
                cur = cur->sibling;
            } else{
                cur = cur->parent;
            }
        }
    }
    return cur;
}

template <class T>
void WeightedKTree<T>::Traverse(){
    if(!root_){
        return;
    }
    KWNode<T> *cur = root_;
    std::set<KWNode<T> *> visited;
    while(cur){
        if(visited.find(cur) != visited.end()){
            cur = cur->sibling ? cur->sibling : cur->parent;
        } else{
            std::cout << cur << " ";
            visited.insert(cur);
            if(cur->f_child){
                cur = cur->f_child;
            } else if(cur->sibling) {
                cur = cur->sibling;
            } else{
                cur = cur->parent;
            }
        }
    }
}
