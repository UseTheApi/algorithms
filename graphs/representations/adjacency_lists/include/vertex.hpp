//
//  vertex.hpp
//  graph representations
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>

template <class T>
class Vertex{
public:
	Vertex(T, int);
	T get_data();
	int get_id();
	template <class V>
	friend std::ostream& operator<<(std::ostream& os, const Vertex<V> *v);
	~Vertex();
private:
	T data;
	int id;
};

template <class T>
Vertex<T>::Vertex(T new_data, int new_id){
	data = new_data;
	id = new_id;
}

template <class T>
T Vertex<T>::get_data(){
	return data;
}

template <class T>
int Vertex<T>::get_id(){
	return id;
}

template <class V>
std::ostream& operator<<(std::ostream& os, const Vertex<V> *v){
	os << v->data;
	return os;
}