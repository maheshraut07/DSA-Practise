#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){

   unordered_map<int , list<int>> adj;

   for(int i = 0; i < e; i++){
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
   }

   // find all indegrees

   vector<int> indegree(v);

   for(auto i : adj){
    for(auto j: i.second){
        indegree[j]++;
    }
    
   }

   // indegree valo ko push kardo 

   queue<int> q;

   for(int i = 0; i < v; i ++){
    if(indegree[i] == 0){
        q.push(i);
    }
   }

   // do bfs

   vector<int> ans;
   
   while(!q.empty()){
    int front = q.front();
    q.pop();

    // ans store

    ans.push_back(front);

    // neighbor indegree upgrade
    for(auto neighbor : adj[front]){
        indegree[neighbor]--;

        if(indegree[neighbor] == 0){
            q.push(neighbor);
        }
    }
   }

   return ans;


} 


