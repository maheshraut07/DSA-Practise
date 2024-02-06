from collections import deque
class Graph:
    def __init__(self):
        self.m = {}

    def add_edge(self, x, y, is_undirected):
        if x not in self.m:
            self.m[x] = []
        self.m[x].append(y)
        if is_undirected:
            if y not in self.m:
                self.m[y] = []
            self.m[y].append(x)

    def print_edges(self):
        for vertex, edges in self.m.items():
            print(f"{vertex} => {', '.join(map(str, edges))}")