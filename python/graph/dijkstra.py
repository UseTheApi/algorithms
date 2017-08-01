"""
Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.

Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree.
Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root.
"""

from .undirected_graph import WGraph
from python.trees.binary_heap_map import init_heap
import unittest


def dijkstra(graph, source_v):
    heap = init_heap(graph, source_v)
    parent = {source_v: None}
    destination = {source_v: 0}
    while not heap.empty():
        cur_value = heap.top()
        cur = heap.extract_min()
        if cur not in destination:
            destination[cur] = cur_value[1]
        else:
            destination[cur] = min(destination[cur], cur_value[1])
        neighbours = graph.adj[cur]
        for n in neighbours:
            name = n[0]
            weight = n[1]
            if name not in parent:
                parent[name] = cur
            if name not in heap.heap_map:
                continue
            else:
                heap.update_value(name, min(destination[cur]+weight, heap.heap_map[name][1]))
    return parent, destination


class TestDijkstra(unittest.TestCase):
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

    def test_dijkstra(self):
        expected_parent = {'a': None, 'b': 'a', 'd': 'a', 'c': 'd', 'e': 'd', 'f': 'c'}
        expected_destination = {'a': 0, 'd': 1, 'c': 2, 'b': 3, 'f': 6, 'e': 7}
        actual_parent, actual_destination = dijkstra(TestDijkstra.graph, 'a')
        self.assertEqual(expected_parent, actual_parent)
        self.assertEqual(expected_destination, actual_destination)
        print(actual_parent)
        print(actual_destination)
