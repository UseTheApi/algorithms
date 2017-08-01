"""
Detect a cycle in an undirected graph.

Note: Disjoint set is used
"""

from .undirected_graph import UGraph
import unittest


def init_graph(edge_list):
    graph = UGraph()
    for edge in edge_list:
        graph.add_edge(edge[0], edge[1])
    return graph


class DisjointSet(object):
    def __init__(self, graph):
        self.parent = dict()
        for v in graph.vertices:
            self.parent[v] = list()

    def find(self, v):
        for vertex in self.parent:
            if v in self.parent[vertex] or v == vertex:
                return vertex
        return None

    def union(self, v1, v2):
        self.parent[v1].append(v2)

    def __str__(self):
        return str(self.parent)


def detect_cycle(given_graph):
    d_set = DisjointSet(graph=given_graph)
    visited_edges = list()
    cycle = False
    for v in given_graph.vertices:
        if cycle:
            break
        neighbours = given_graph.adj[v]
        v_subset = d_set.find(v)
        for n in neighbours:
            if (v, n) in visited_edges or (n, v) in visited_edges:
                continue
            visited_edges.append((v, n))
            if v_subset == d_set.find(n):
                cycle = True
                break
            else:
                d_set.union(v, n)
    print("Result Disjoint Set:", d_set)
    return cycle


class TestUndirectedGraphCycle(unittest.TestCase):

    def test_SimpleCycleGraph(self):
        print("==== 3 Nodes cycle ====")
        g = init_graph([(0, 1), (0, 2), (1, 2)])
        print("Given Graph:")
        g.print_graph()
        self.assertTrue(detect_cycle(g))

    def test_5NodesGraph(self):
        print("==== 5 Nodes cycle ====")
        g = init_graph([
            (0, 1), (0, 2),
            (1, 3), (1, 4),
            (3, 4)
        ])
        print("Given Graph:")
        g.print_graph()
        self.assertTrue(detect_cycle(g))

    def test_NoCycleGraph(self):
        print("==== 5 Nodes No Cycle ====")
        g = init_graph([
            (0, 1), (0, 2),
            (1, 3),
            (3, 4)
        ])
        print("Given Graph:")
        g.print_graph()
        self.assertFalse(detect_cycle(g))
