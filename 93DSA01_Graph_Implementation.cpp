// code for implementation of graph by using adjacent list by using unordered map

#include<iostream>
#include<unordered_map>
#include<map>
#include<set>
#include<list>

using namespace std;

class graph{

    public:

    unordered_map<int, list<int>> adjList;   // we will implement graph by using adjacency list by using map
                                             // if you want the numbers in the list in ascending order the use the set instead of list

    void addEdge(int u, int v, bool direction ){
        // directed graph => direction = 1;
        // undirected graph => direction = 0;

        // create and edge from u to v

        adjList[u].push_back(v);

        // if graph is undirected
        if(direction == 0){
            adjList[v].push_back(u);
        } 
    }

    void printAdjList(){
        for(auto i : adjList){
            cout << i.first << " => " ;

            for(auto j : i.second){
                cout << j << "-> ";
            }
            cout << "NULL";
            cout << endl;
        }
    }
};


int main(){

    graph g;

    int n , m;
    cout << "Enter the number of nodes in the graph : ";
    cin >> n;
    cout << "\nEnter the number of edges in the graph: ";
    cin>> m;

    

    for(int i = 0; i < m; i++){
        cout <<"\nEnter source -> destination : ";
        int u , v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;

}