#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

void dfs(int node, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &component) {
       
        component.push_back(node);
        visited[node] = true;

        for (auto i : adj[node]) {
            if (visited[i] == false) {
                dfs(i, adj, visited, component);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                vector<int> component;
                dfs(i, adj, visited, component);
                ans = component;
            }
        }
    
        return ans;
    }

    // TC  = linear, SC = linear