//
//  edge_classification.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

/*
 Edge Classification.

 Approaches:
 	1. Tree edges returns DFS itself within Parent structure
 	2. Backward edges: mark which vertices we are currently exploring in DFS. 
 	   If the edges that currently being explored leads to a vertex that has been makred as 'started', 
 	   then it's a backward edge
 	3. Forward edges: count steps of DFS algorithms and store them in a vertex structure. 
 	   This would tell us time we explored every node and can help to recognize forward edges from cross edges
*/