#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 void bfs(vector<int> adj[], unordered_map<int, bool>& visited, vector<int>& ans, int node) {
        queue<int> q;
        q.push(node);
    
        visited[node] = true;  

        while (!q.empty()) {
            int frontNode = q.front();          // 1) taking the frontNode from the queue
            q.pop();                             //2)  pop the frontNode from the queue

            ans.push_back(frontNode);              //3) after popping the frontNode from the queue push back the frontNode in the ans ;

            for (auto i : adj[frontNode]) {        // 4)push all the non visited adjacent nodes of the frontNode in the queue and mark them as visited
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
            }
        }
    }
}

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        vector<int> ans;

        for (int i = 0; i < V; i++) {             // inserting for all nodes whether it is connected or disconnected
            if (!visited[i]) {                     // visited[i] == false;
                bfs(adj, visited, ans, i);
        }
        }

        return ans;
    }

// GFG question