//
//  add_to_graph.hpp
//  graphs. graph application tasks. utils file
//
//  Created by alifar on 01/23/17.
//  Copyright © 2016 alifar. All rights reserved.
//

void AddToGraph(Graph<char, VertexEc> *graph, char ch1, char ch2){
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