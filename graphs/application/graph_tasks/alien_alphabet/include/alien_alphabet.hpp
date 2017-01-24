//
//  alien_alphabet.hpp
//  graphs. graph application tasks
//
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

void CalculateAlphabet(std::vector<std::string> words){
	Graph<char, VertexEc> *graph = new Graph<char, VertexEc>(true); // Initializing Directed Graph
	std::string cur_word;
	std::string next_word;
	for(int i = 0; i < words.size()-1; ++i){
		cur_word = words[i];
		next_word = words[i+1];
		for(int j = 0; j < std::min(words[i].size(), words[i+1].size()); ++j){
			if(cur_word[j] != next_word[j]){
				AddToGraph(graph, cur_word[j], next_word[j]);
				std::cout << "Dependency found: ";
				std::cout << cur_word[j] << " - " << next_word[j] << std::endl;
				break;
			}
		}
	}
	std::cout << "---> Vertices added to a Graph" << std::endl;
	graph->display_vertices();
	std::cout << "---> Running Topological Sort" << std::endl;
	std::vector<VertexEc<char> *> sorted_result = TopologicalSort(graph);
	std::cout << "---> Topologically sorted Vertices (Alien Alphabet): " << std::endl;
	for(auto it: sorted_result){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}
