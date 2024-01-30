//creating and printing the graph by using vector
//codestudio question
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}



vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    
    vector<vector<int>> ans(n);

    // ans array will store all neighbors adjacent nodes corresponding indexes(adjacency list)
    for(int i = 0; i < m; i++){
        int u = edges[i][0];  // source node 
        int v = edges[i][1];  // destination node 

        ans[u].push_back(v);
        ans[v].push_back(u); // because the graph is undirected
    }

    vector<vector<int>> adjList(n);

    for(int i = 0; i < n; i++){
        adjList[i].push_back(i);  // push the current node into the list

        // entering all the neighbors into the final list

        for(int j = 0; j < ans[i].size(); j++){
            adjList[i].push_back(ans[i][j]);
        }
    }

    return adjList;
}


/*


Let's take three edges as an example: (0, 1), (1, 2), and (2, 0). The goal is to create an adjacency list based on these edges.

Initialize the variables:

n (number of nodes) = 3
m (number of edges) = 3
edges (edge list) = {(0, 1), (1, 2), (2, 0)}
Create the ans array:

cpp
Copy code
ans[0]: {1}
ans[1]: {0, 2}
ans[2]: {1, 0}
Create the adjList array:

Initialize adjList as an empty vector of vectors.
Loop through each node and its neighbors in ans to populate adjList.
After the loop:

cpp
Copy code
adjList[0]: {0, 1}
adjList[1]: {1, 0, 2}
adjList[2]: {2, 1, 0}
So, the final adjacency list would be:

cpp
Copy code
{
  {0, 1},
  {1, 0, 2},
  {2, 1, 0}
}
This represents an undirected graph with three nodes and three edges: (0, 1), (1, 2), and (2, 0). Each node in the graph is connected to its neighbors as described in the adjacency list.

*/
