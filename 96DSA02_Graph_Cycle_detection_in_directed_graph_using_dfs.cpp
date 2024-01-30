#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool isCycleDfs(int node, int parent , unordered_map<int , list<int>> &adjList, unordered_map <int , bool> &visited){

    visited[node] = true;

    for(auto neighbor : adjList[node]){
        if(visited[neighbor] == false){
            bool isCyclePresent = isCycleDfs(neighbor, node,adjList,visited );

            if(isCyclePresent) return true;    // cycle is present;
        }

        else if(neighbor != parent) return true;   // cycle is present;
    }

    return false;     // cycle is not present
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //crete adjacency list

    unordered_map<int , list<int>> adjList;

    for(int i = 0;  i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }

    unordered_map <int , bool> visited;

    // for handling the case in which graph will be disconnected
    // to track the all nodes 

    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            bool ans = isCycleDfs(i,-1,  adjList, visited);
            if(ans == true) return "Yes";
        }
    }

    return "No";


}