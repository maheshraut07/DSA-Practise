#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}



bool detectCycleDfs(int node,unordered_map< int, bool> &visited,unordered_map<int, bool>& dfsVisited , unordered_map<int, list<int>>& adjList ){
  
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto neighbor : adjList[node]){
    if(visited[neighbor] == false){
      bool cycleDetected = detectCycleDfs(neighbor, visited, dfsVisited, adjList);
      if(cycleDetected) return true;
    }
    
    else if(dfsVisited[neighbor] == true) return true;
  }

  dfsVisited[node] = false;

  return  false;


}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adjList[u].push_back(v);
    }

    unordered_map< int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 0; i < n; i++){
        if(visited[i] == false){
          bool cycleDetect = detectCycleDfs(i, visited, dfsVisited, adjList);
          if(cycleDetect) return true;
        }
    }

    return false;

}