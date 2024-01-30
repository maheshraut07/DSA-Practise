#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool isCycleBfs(int source, unordered_map<int , list<int>> &adjList,
                 unordered_map <int , bool> &visited ){
    
    queue<int> q;
    unordered_map <int,int> parent;

    parent[source] = -1;
    visited[source] = true;

    q.push(source);

    while(!q.empty()){

        int frontNode = q.front();
        q.pop();
        
        // for keeping track of all neighbor nodes of frontNode 
        for(auto Neighbor: adjList[frontNode]){
            if(visited[Neighbor] == true && Neighbor != parent[frontNode]){   // for checking the condition if cycle is present or not 
                return true;
            }

            else if( visited[Neighbor] == false){
                q.push(Neighbor);
                visited[Neighbor] = true;
                parent[Neighbor] = frontNode;
            }
        }


    }

    return false;
    
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
            bool ans = isCycleBfs(i, adjList, visited);
            if(ans == true) return "Yes";
        }
    }

    return "No";


}