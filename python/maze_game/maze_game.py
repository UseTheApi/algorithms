# !/bin/python

"""
Problem: There is a maze game where the ball can go in any of 4 directions. It can go all the way
until it hits a wall or a block. Determine whether the ball can hit the exit cell.

Notes: 
    * I decided to represent walls as a list of tuples. They are indicating the map.
    * Start cell and maze exit cell are also tuples
    * size is indicating a size of maze.
    * I build a graph from these given data determining states (moves) of the ball as vertices of
    the graph.
"""

walls = [(0, 0), (0, 5), (2, 5), (3, 1), (3, 2), (3, 5), (5, 0), (5, 2), (5, 3), (5, 5)]

start = (5, 3)

maze_exit = (2, 0)

size = 5


class Vertex(object):
    def __init__(self, coordinate: tuple):
        self.__first = coordinate[0]
        self.__second = coordinate[1]
        self.__neighbours = list()
        self.__visited = False

    @property
    def first(self):
        return self.__first

    @property
    def second(self):
        return self.__second

    @property
    def neighbours(self):
        return self.__neighbours

    @property
    def visited(self):
        return self.__visited

    @visited.setter
    def visited(self, value: bool):
        self.__visited = value

    def __str__(self):
        return '{0} {1}'.format(self.first, self.second)

    def __getitem__(self, item):
        if item == 0:
            return self.first
        if item == 1:
            return self.second

    def __eq__(self, other):
        return self.first == other.first and self.second == other.second


def construct_edge_tuples(vertex):
    return [(0, vertex.second), (size, vertex.second), (vertex.first, 0), (vertex.first, size)]


def get_neighbours(vertex, blocks):
    potential_neighbours = [neighbour for neighbour in blocks
                            if vertex.first == neighbour[0] or vertex.second == neighbour[1]]
    potential_neighbours = list(set().union(potential_neighbours, construct_edge_tuples(vertex)))
    return potential_neighbours


def more_then_by_item(vertex1, vertex2, item_to_compare):
    return vertex1[item_to_compare] > vertex2[item_to_compare]


def validate_n(vertex: Vertex, neighbour: Vertex, blocks):
    for i in range(0, 2):
        index_to_compare = i+1 if not i else i-1
        if vertex[i] == neighbour[i]:
            coordinate_range = range(neighbour[index_to_compare]-1, vertex[index_to_compare], -1) \
                if more_then_by_item(neighbour, vertex, index_to_compare) \
                else range(vertex[index_to_compare]-1, neighbour[index_to_compare], -1)

            if not coordinate_range:
                return False
            for step in coordinate_range:
                step_tuple = (step, vertex[i]) if not index_to_compare else (vertex[i], step)
                if step_tuple in blocks:
                    return False
    return True


class Graph(object):
    def __init__(self):
        self.__vertices = list()

    @property
    def vertices(self):
        return self.__vertices

    def add_edge(self, vertex, neighbour):
        if vertex not in self.vertices:
            self.vertices.append(vertex)
        if neighbour not in self.vertices:
            self.vertices.append(neighbour)

        if neighbour not in vertex.neighbours:
            vertex.neighbours.append(neighbour)

    def get_vertex_from_tuple(self, vertex_tuple):
        existing_v = [vertex for vertex in self.vertices
                      if vertex.first == vertex_tuple[0] and vertex.second == vertex_tuple[1]]
        return existing_v[0] if existing_v else Vertex(vertex_tuple)

    def print_graph(self):
        print("Printing")
        index = 0
        for v in self.vertices:
            print("round: ", index)
            print(v, end=' -> ' if v.neighbours else '\n')
            for index, n in enumerate(v.neighbours):
                print(n, end=' -> ' if index != len(v.neighbours) - 1 else '\n')
            index += 1
        print()


def find_exit(graph, start_coordinate, exit_coordinate):
    start_vertex = Vertex(start_coordinate)
    stack = list()
    stack.append(start_vertex)

    while stack:
        cur_v = stack.pop()
        cur_v.visited = True
        print("CURRENT", cur_v)
        for neighbour in get_neighbours(cur_v, walls):
            neighbour_v = graph.get_vertex_from_tuple(neighbour)
            if validate_n(cur_v, neighbour_v, walls) and cur_v != neighbour_v:
                graph.add_edge(cur_v, neighbour_v)
                stack.append(neighbour_v) if not neighbour_v.visited else None
    graph.print_graph()
    return True if Vertex(exit_coordinate) in graph.vertices else False


if __name__ == "__main__":
    graph = Graph()
    print("FOUND EXIT") if find_exit(graph, start, maze_exit) else print("EXIT WAS NOT FOUND")
