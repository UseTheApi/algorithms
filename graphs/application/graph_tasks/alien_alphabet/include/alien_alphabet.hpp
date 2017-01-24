//
//  alien_alphabet.hpp
//  graphs. graph application tasks
//
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <topological_sort.hpp>
#include <vector>
#include <string>
#include <iostream>

void AddToGraph(Graph<char, VertexEc> *graph, char ch1, char ch2){
	// std::vector<VertexEc<char> *> v = graph->get_vertices();
	// for(auto it: v){
	// 	std::cout << "WOW";
	// 	std::cout << it << " ";
	// }
	int i1, i2;
	if( graph->empty ){
		i1 = graph->add_vertex(ch1);
		i2 = graph->add_vertex(ch2);
	} else{
		VertexEc<char> *v1 = graph->get_vertex_by_value(ch1);
		VertexEc<char> *v2 = graph->get_vertex_by_value(ch2);
		
		i1 = v1 ? v1->get_id() : graph->add_vertex(ch1);
		i2 = v2 ? v2->get_id() : graph->add_vertex(ch2);
	}
	graph->add_edge(i1, i2);
}

void AnalizeDictionary(std::vector<std::string> words){
	Graph<char, VertexEc> *graph = new Graph<char, VertexEc>(true); // Initializing Directed Graph

	for(int i = 0; i < words.size()-1; ++i){
		std::cout << words[i] << " " << words[i+1] << std::endl;
		std::string cur_word = words[i];
		std::string next_word = words[i+1];
		for(int j = 0; j < std::min(words[i].size(), words[i+1].size()); ++j){
			if(cur_word[j] != next_word[j]){
				AddToGraph(graph, cur_word[j], next_word[j]);
				std::cout << cur_word[j] << " - " << next_word[j] << std::endl;
				break;
			}
		}
	}
	graph->display_vertices();
	std::cout << std::endl;
}
