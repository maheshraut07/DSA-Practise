#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}




vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map < int , list<int>> adj;
	
	for(int i = 0; i < edges.size(); i++){    // preparing adjcency list
		
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	unordered_map<int, bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);

	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){                           // bfs traversal
		int front = q.front();
		q.pop();

		for(auto i: adj[front]){
			if(visited[i] == false){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}


	// prepate shortest path

	vector<int> ans;
	int currentNode = t;

	ans.push_back(t);

	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
    
	reverse(ans.begin(), ans.end());
	return ans;
}


/*
s = source
t = terminal
n = number of vertex
m = number of edges
*/