/*

this code is for finding out the shortest path in the directed acyclic graph
*/

#include<bits/stdc++.h>
using namespace std;

class graph{
    
    public:
    
    unordered_map < int, list<pair<int,int> > > adjList;

    void addEdge(int u, int v, int weight){   // function for making the adjacency list

        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }
    
    void printAdjList(){   // function for printing the list
        
        for(auto i : adjList){
            cout << i.first << " -> ";

            for(auto j : i.second){
                cout << "(" << j.first << "," << j.second << "), " ;
            }

            cout << endl;
        }
    }

    void topodfs(int node, unordered_map<int, bool> &vis , stack<int> &st){          // this function is for finding the topological sort 

        vis[node] = true;

        for(auto  &neighbor : adjList[node]){
            if(!vis[neighbor.first]){
                topodfs(neighbor.first, vis, st);
            }
        }

        st.push(node);
    }

    // function for getting shortest path

    void getShortestPath(int src, vector<int> &distance, stack<int> & st){

        distance[src] = 0;

        while(!st.empty()){

            int top = st.top();
            st.pop();

            for(auto i : adjList[top]){
                if(distance[top] + i. second < distance[i.first]){
                    distance[i.first] = distance[top] + i. second;
                }
            }
        }
    }

};

int main(){

     graph g;

     g.addEdge(8,1,5);
     g.addEdge(0,2,3);
     g.addEdge(1,2,2);
     g.addEdge(1,3,6);
     g.addEdge(2,3,7);
     g.addEdge(2,4,4);
     g.addEdge(2,5,2);
     g.addEdge(3,4,-1);
     g.addEdge(4,5,-2);
     
     cout << endl;
     g.printAdjList();
     cout << endl;


     int n = 6 ; // number of nodes

     unordered_map<int, bool> visited;  // for maintaining track of visited node
     stack <int> s;

     for(int i = 0; i < n; i++){         // for making topoligical sort stack

        if(!visited[i]){
            g.topodfs(i, visited, s);
        }
    }


    // for making the distance array

    int src = 1;

    vector <int> distance(n);

    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
    }


    // make the source entry in the distance array
    
    g.getShortestPath(src, distance, s);
    
    cout << "our answer array is  ; ";
    for(int i = 0; i < distance.size(); i++){
        cout << distance[i] << " " ;
    }

    cout << endl;






    return 0;

}