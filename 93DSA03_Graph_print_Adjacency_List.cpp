#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {

        // Initialize the adjacency list
        vector<vector<int>> adjList(V);

        // Iterate through the edges and populate the adjacency list
         for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return adjList;
    }


// using  vector
//this question is from gfg
// print the adjacency list of the graph