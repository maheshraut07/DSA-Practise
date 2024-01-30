#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

void dfs(int node, unordered_map<int, list<int>> &adj,unordered_map<int, bool> & visited, vector<int> &component  ){

    component.push_back(node);
    visited[node] = true;

    // recurrsive call for every connected node

    for(auto i : adj[node]){
        if(visited[i] == false){
            dfs(i,adj,visited,component);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;    // preparation of adjacent list 

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;    // visited map 
    vector<vector<int>> ans;             // ans array
     

    for(int i = 0; i < V; i++){

        if(visited[i] == false){
            vector<int> component;

            dfs(i,adj, visited, component);   
            ans.push_back(component);
        }

    }

    return ans;
}

// codestudio