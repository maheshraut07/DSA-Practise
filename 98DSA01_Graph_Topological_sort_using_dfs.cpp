#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


void toposort(stack<int> &s, int node, unordered_map<int , list<int>> &adjList ,vector<bool> &visited){

    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(visited[neighbour] == false){
            toposort(s , neighbour, adjList, visited);
        }
    }

    s.push(node);         // if it is not possible to visit the node again then push it into the stack
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   
   unordered_map<int , list<int>> adjList;

   for(int i = 0; i < e; i++){
       int u = edges[i][0];
       int v = edges[i][1];

       adjList[u].push_back(v);
   }

   vector<bool> visited(v);
   stack<int> s;                        

   for(int i = 0; i < v; i ++){
       if(visited[i] == false){
           toposort(s, i,adjList, visited );
       }
   }

   vector<int> ans;

   while(!s.empty()){
       int num = s.top();
       s.pop();
       ans.push_back(num);
   }

   return ans;
}