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

    def bfs(self, start):
        visited = set()
        queue = deque([start])
        result = []

        while queue:
            current_vertex = queue.popleft()
            if current_vertex not in visited:
                result.append(current_vertex)
                visited.add(current_vertex)
                queue.extend(self.m[current_vertex])

        return result

    def dfs(self, start, visited=None, result=None):
        if visited is None:
            visited = set()
        if result is None:
            result = []

        result.append(start)
        visited.add(start)

        for neighbor in self.m.get(start, []):
            if neighbor not in visited:
                self.dfs(neighbor, visited, result)

        return result

def main():
    g = Graph()

    n = int(input("Enter the number of nodes you want to add: "))
    m = int(input("Enter the number of edges you want: "))

    for i in range(m):
        x, y = map(int, input(f"Enter the source and destination for edge {i}: ").split())
        g.add_edge(x, y, True)

    print("\nThe adjacency list for the given graph is:")
    g.print_edges()

    start_vertex = int(input("\nEnter the starting vertex for BFS traversal: "))
    bfs_result = g.bfs(start_vertex)

    print("\nBFS Traversal:")
    print(bfs_result)

    dfs_result = g.dfs(start_vertex)
    print("\nDFS Traversal:")
    print(dfs_result)

if __name__ == "__main__":
    main()


''' In Python, the self parameter is a convention that refers to the instance of the class. It is similar to the use of this in other object-oriented programming languages. When you define methods in a class, including the __init__ method, you need to include self as the first parameter. This allows the methods to access and modify the object's attributes.

Here's a brief explanation of the usage of self in Python classes:

__init__ method:

self is used to represent the instance of the class.
It allows you to access and modify the instance variables (attributes) within the class.
Other methods:

All methods within a class, including those you define (like add_edge, print_edges, bfs, and dfs), should have self as their first parameter.
It enables these methods to access and modify the attributes of the instance.
In the provided code, self is used to refer to the instance of the Graph class. It allows methods to interact with the graph data stored in the class instance. If you don't use self, the methods won't have access to the instance's data and won't be able to operate on it.

Here's a modified version without the use of self in the methods. However, note that this is not a recommended practice, and using self conforms to standard Python conventions for defining methods in classes:

python
Copy code
class Graph:
    def __init__(self):
        self.m = {}

    def add_edge(x, y, is_undirected):
        if x not in Graph.m:
            Graph.m[x] = []
        Graph.m[x].append(y)
        if is_undirected:
            if y not in Graph.m:
                Graph.m[y] = []
            Graph.m[y].append(x)

    def print_edges():
        for vertex, edges in Graph.m.items():
            print(f"{vertex} => {', '.join(map(str, edges))}")

    def bfs(start):
        visited = set()
        queue = deque([start])
        result = []

        while queue:
            current_vertex = queue.popleft()
            if current_vertex not in visited:
                result.append(current_vertex)
                visited.add(current_vertex)
                queue.extend(Graph.m[current_vertex])

        return result

    def dfs(start, visited=None, result=None):
        if visited is None:
            visited = set()
        if result is None:
            result = []

        result.append(start)
        visited.add(start)

        for neighbor in Graph.m.get(start, []):
            if neighbor not in visited:
                Graph.dfs(neighbor, visited, result)

        return result
In practice, using self is the recommended approach to make your code more readable and adhere to standard conventions.'''