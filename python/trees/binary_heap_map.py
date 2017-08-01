class MinHeapMap(object):
    min_int = -9999999999
    max_int = 9999999999

    def __init__(self):
        self.heap_map = dict()
        self.array = list()
        self.last_index = -1

    def empty(self):
        return True if self.last_index < 0 else False

    def parent(self, i):
        if 1 > i > len(self.array):
            return -1
        return (i - 1)//2

    def left(self, i):
        if 0 > i > len(self.array):
            return -1
        left_i = 2*i+1
        return left_i if left_i <= self.last_index else -1

    def right(self, i):
        if 0 > i > len(self.array):
            return -1
        right_i = 2*i+2
        return right_i if right_i <= self.last_index else -1

    def contains(self, key):
        if key in self.heap_map:
            return self.heap_map[key]  # tuple represents position in Heap and weight
        return 0

    def sift_up(self, index):
        key = self.array[index]
        value = self.heap_map[key][1]
        while index and index > -1:
            parent_i = (self.parent(index))
            parent_v = self.array[parent_i]
            if self.heap_map[parent_v][1] > value:
                self.heap_map[parent_v][0] = index
                self.heap_map[key][0] = parent_i
                self.array[index], self.array[parent_i] = self.array[parent_i], self.array[index]
            index = parent_i

    def decrease_key(self, key):
        if key not in self.heap_map:
            return
        self.heap_map[key][1] = MinHeapMap.min_int
        self.sift_up(key)

    def more_then(self, index1, index2):
        value1 = self.heap_map[self.array[index1]][1]
        value2 = self.heap_map[self.array[index2]][1]
        return value1 < value2

    def heapify(self, index):
        index_of_min = index
        left_index = self.left(index)
        right_index = self.right(index)
        while not index or self.more_then(left_index, index) or self.more_then(right_index, index):
            if 0 < left_index <= self.last_index and self.more_then(left_index, index):
                index_of_min = left_index
            if 0 < right_index <= self.last_index and self.more_then(right_index, index_of_min):
                index_of_min = right_index
            if index_of_min != index:
                self.heap_map[self.array[index_of_min]][0] = index
                self.heap_map[self.array[index]][0] = index_of_min
                self.array[index_of_min], self.array[index] = self.array[index], self.array[index_of_min]
                index = index_of_min
                left_index = self.left(index)
                right_index = self.right(index)
            else:
                return
            if left_index < 0 and right_index < 0:
                return

    def update_value(self, key, new_value):
        index = self.heap_map[key][0]
        self.heap_map[key][1] = new_value
        self.sift_up(index)

    def insert(self, key, value):
        self.array.append(key)
        self.last_index += 1
        self.heap_map[key] = [self.last_index, value]
        self.sift_up(self.last_index)

    def extract_min(self):
        if self.last_index < 0:
            return
        top_v = self.array[0]
        del self.heap_map[top_v]

        if not self.last_index:
            self.last_index -= 1
            return top_v
        self.array[0] = self.array[self.last_index]
        self.heap_map[self.array[0]][0] = 0
        self.last_index -= 1
        self.array.pop()
        self.heapify(0)
        return top_v

    def top(self):
        if self.last_index < 0:
            return None
        return self.heap_map[self.array[0]]


def init_heap(graph, start_vertex):
    heap = MinHeapMap()
    for v in graph.vertices:
        if v == start_vertex:
            heap.insert(v, 0)
            continue
        heap.insert(v, heap.max_int)
    return heap
