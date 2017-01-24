//
//  solution_with_topo_sort_implemented.hpp
//  graphs. graph application tasks. the whole solution in place. 
//  For project solution check alien_alphabet.hpp
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <string>
#include <iostream>

void AnalizeDictionary(Graph<char, VertexEc> *graph, std::vector<std::string> dict){
	std::string cur_word;
	std::string next_word;
	for(int i = 0; i < dict.size()-1; ++i){
		cur_word = dict[i];
		next_word = dict[i+1];
		for(int j = 0; j < std::min(cur_word.size(), next_word.size()); ++j){
			if(cur_word[j] != next_word[j]){
				AddToGraph(graph, cur_word[j], next_word[j]);
				break;
			}
		}
	}
}

void topological_sort_local(Graph<char, VertexEc> *graph, VertexEc<char> *root_v, std::vector<char> &result){
	root_v->visited = true;
	LinkedList<VertexEc<char> *> adj_list = graph->get_adj()[root_v->get_id()];
	for(auto u: adj_list){
		if(root_v == u){
			continue;
		}
		if(!u->visited){
			u->visited = true;
			u->add_type(root_v, EdgeType::kTree);
			topological_sort_local(graph, u, result);
		}
	}
	if(!root_v->finished){
		root_v->finished = 1;
		result.insert(result.begin(), root_v->get_data());
	}
}

std::vector<char> CollectChars(Graph<char, VertexEc> *graph){
	std::vector<char> result;
	for(auto v: graph->get_vertices()){
		topological_sort_local(graph, v, result);
	}
	return result;
}


std::vector<char> ComputeAlphabet(std::vector<std::string> dict){
	Graph<char, VertexEc> *graph = new Graph<char, VertexEc>(true);
	AnalizeDictionary(graph, dict);
	std::vector<char> result_alphabet = CollectChars(graph);
	delete graph;
	return result_alphabet;
}