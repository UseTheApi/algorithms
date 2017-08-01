"""
Given a connected and undirected graph, a spanning tree of that graph is a sub-graph that is a tree
and connects all the vertices together.
A single graph can have many different spanning trees. A
 minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected graph
 is a spanning tree with weight less than or equal to the weight of every other spanning tree.
 The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

Note: Kruskal's Algorithm is used.

1. Sort all the edges in non-decreasing order of their weight.

2. Pick the smallest edge. Check if it forms a cycle with the spanning tree
formed so far. If cycle is not formed, include this edge. Else, discard it.

3. Repeat step#2 until there are (V-1) edges in the spanning tree.
"""

from .undirected_graph import WGraph
from .detect_cycle_undirected_graph import DisjointSet
import unittest


def kruskal_mst(graph: WGraph):
    all_edges = graph.unique_edges()
    d_set = DisjointSet(graph)
    mst = list()
    # Sort all edges by weight
    all_edges = sorted(all_edges, key=lambda x: x[2])
    print(all_edges)
    e = 0
    while len(mst) < len(graph.vertices) - 1 and e < len(all_edges):
        edge = all_edges[e]
        v1 = edge[0]
        v2 = edge[1]
        e += 1
        if d_set.find(v1) == d_set.find(v2):
            continue
        d_set.union(v1, v2)
        mst.append(edge)
    return mst


class TestMST(unittest.TestCase):

    def test_Kruskal(self):
        graph = WGraph()
        graph.add_edge('a', 'b', 3)
        graph.add_edge('a', 'd', 1)
        graph.add_edge('b', 'd', 3)
        graph.add_edge('b', 'c', 1)
        graph.add_edge('c', 'd', 1)
        graph.add_edge('d', 'e', 6)
        graph.add_edge('c', 'e', 5)
        graph.add_edge('c', 'f', 4)
        graph.add_edge('f', 'e', 2)
        graph.print_graph()

        expected = [('a', 'd', 1), ('b', 'c', 1), ('d', 'c', 1), ('e', 'f', 2), ('c', 'f', 4)]

        self.assertEqual(expected, kruskal_mst(graph))
