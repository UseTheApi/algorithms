"""
Minimum Spanning Tree (MST) problem:
Given connected graph G with positive edge weights, find a min weight set of edges that connects all of the vertices.

Note: Prim's Greedy Algorithm is used here
"""

from python.trees.binary_heap_map import MinHeapMap
from .undirected_graph import WGraph
import unittest


def init_heap(graph, start_vertex):
    heap = MinHeapMap()
    for v in graph.vertices:
        if v == start_vertex:
            heap.insert(v, 0)
            continue
        heap.insert(v, heap.max_int)
    return heap


def prim_min_spanning_tree(graph, start_v):
    heap = init_heap(graph, start_v)
    visited = dict()
    result = list()
    while not heap.empty():
        min_v = heap.extract_min()
        if min_v in visited.keys():
            result.append(visited[min_v])
        neighbours = graph.adj[min_v]
        for neighbour in neighbours:
            neighbour_name = neighbour[0]
            neighbour_weight = neighbour[1]
            if neighbour_name not in heap.heap_map:
                continue
            if neighbour_weight < heap.heap_map[neighbour_name][1]:
                heap.update_value(neighbour_name, neighbour_weight)
                visited[neighbour_name] = (min_v, neighbour_name)
    return result


class TestMST(unittest.TestCase):
    graph = None

    @classmethod
    def setUpClass(cls):
        cls.graph = WGraph()
        cls.graph.add_edge('a', 'b', 3)
        cls.graph.add_edge('a', 'd', 1)
        cls.graph.add_edge('b', 'd', 3)
        cls.graph.add_edge('b', 'c', 1)
        cls.graph.add_edge('c', 'd', 1)
        cls.graph.add_edge('d', 'e', 6)
        cls.graph.add_edge('c', 'e', 5)
        cls.graph.add_edge('c', 'f', 4)
        cls.graph.add_edge('f', 'e', 2)
        cls.graph.print_graph()

    def test_MST_a(self):
        expected = [('a', 'd'), ('d', 'c'), ('c', 'b'), ('c', 'f'), ('f', 'e')]
        actual = prim_min_spanning_tree(graph=TestMST.graph, start_v='a')
        print("Got MST from source {}:".format('a'), actual)
        self.assertEqual(expected, actual)
