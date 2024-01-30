/*

You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 
1
Explanation: 
Every node is reachable and the graph has no loops, so it is a tree
Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 
0
Explanation: 
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adjList ){
        bool ans = 1;
        visited[node] = 1;
        
        for(auto neighbor : adjList[node]){
            if(visited[neighbor] == 0){
                ans = ans and dfs(neighbor, node, visited, adjList);
            }
            else if(neighbor != parent){
                return 0;
            }
                
        }
        
        return ans;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
       if(m != n-1) return 0;
       
       vector <vector<int>> adjList(n);
       
       for(int i = 0; i < m; i++){   // make the adjacency list 
           int u = adj[i][0];
           int v = adj[i][1];
           
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
       
       vector<int> visited(n,0);   // for tracking of the node that particular node is visited or not 
       bool ans = 1;
       int cc = 0;   // component connected to a particlar node 
       
       for(int i = 0; i < n; i++){  // treversing through all the nodes 
           
           if(visited[i] == 0) {// if particular node is not visited then visit it by bfs
               ans = ans && dfs(i , -1, visited, adjList);
               ++cc;
           } 
           
       }
       
       return ans and cc == 1;
    }