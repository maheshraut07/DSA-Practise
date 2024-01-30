#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> Mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        Mst[i] = false;
    }

    // Start the algorithm
    key[1] = 0;
    parent[1] = -1;

    // Find the minimum key from the key array
    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u;

        // Find the minimum value node
        for (int j = 1; j <= n; j++) {
            if (Mst[j] == false && key[j] < mini) {
                u = j;
                mini = key[j];
            }
        }

        // Mark min node in the MST as true;
        Mst[u] = true;

        // Check its adjacent nodes;
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (Mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}