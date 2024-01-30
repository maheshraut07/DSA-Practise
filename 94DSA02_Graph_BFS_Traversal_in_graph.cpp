#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


void prepareAdjLits(unordered_map<int, set<int>> &adjList,vector<vector<int>> &adj ){
    for(int i = 0; i < adj.size(); i++){

        int u = adj[i][0];
        int v = adj[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int> >&adjList,unordered_map<int ,bool> &visited , vector<int> &ans, int node){

    queue<int> q;
    
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans;
        ans.push_back(frontNode);
        

        // traverse all neighbors of frontNode
        for(auto i : adjList[frontNode]){
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }

        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){


    unordered_map<int, set<int>> adjList;
    unordered_map<int ,bool> visited;
    vector<int> ans;
    
    // prepare the adjacency list 
    prepareAdjLits(adjList, adj);


    // traverse all the components of the graph

    for(int i = 0; i< n; i++){
        if(visited[i] == 0){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// codestudio question