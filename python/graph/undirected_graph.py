"""
Simple Undirected Weighted Graph implementation
"""

from abc import ABCMeta, abstractmethod


class Graph(metaclass=ABCMeta):
    def __init__(self):
        self.vertices = list()
        self.adj = dict()

    def add_vertex(self, new_vertex):
        if new_vertex not in self.vertices:
            self.vertices.append(new_vertex)

    @abstractmethod
    def add_edge(self, key1, key2, w=0):
        pass

    def print_graph(self):
        for key in self.adj:
            print(key, ":", self.adj[key])


class WGraph(Graph):

    def add_edge(self, key1, key2, weight=0):
        self.add_vertex(key1)
        self.add_vertex(key2)
        if key1 not in self.adj:
            self.adj[key1] = [(key2, weight)]
        else:
            self.adj[key1].append((key2, weight))
        if key2 not in self.adj:
            self.adj[key2] = [(key1, weight)]
        else:
            self.adj[key2].append((key1, weight))

    def unique_edges(self):
        all_edges = list()
        visited = list()
        for v in self.vertices:
            neighbours = self.adj[v]
            visited.append(v)
            for n in neighbours:
                if n[0] in visited:
                    continue
                all_edges.append((v, n[0], n[1]))
        return all_edges


class UGraph(Graph):

    def add_edge(self, key1, key2, w=0):
        self.add_vertex(key1)
        self.add_vertex(key2)
        if key1 not in self.adj:
            self.adj[key1] = [key2]
        else:
            self.adj[key1].append(key2)
        if key2 not in self.adj:
            self.adj[key2] = [key1]
        else:
            self.adj[key2].append(key1)
