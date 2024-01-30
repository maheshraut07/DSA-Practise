#include<iostream>
#include<map>
#include<list>
using namespace std;

class graph{
    public:

    map<int, list<int>> m;

    void addedge(int x, int y,bool z ){

        m[x].push_back(y);
        if(z == 0) {            // means graph is undirected;
            m[y].push_back(x);
        }
    }

    void printedge(){
        for(auto i: m){
            cout << i.first << " => ";
            
            for(auto edge : m[i.first]){
                cout << edge << " , " ;
            }

            cout << endl;
        }
    }

};

int main(){

    graph g ;
    int n,m ;

    cout << " enter the number of nodes do you want to add :" << endl;
    cin >> n;

    cout << "enter the number of edgese do you want: "<< endl;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x , y;
        cout << "enter the source and destination edge for edge " << i << " :";
        cin >> x >> y;
        g.addedge(x,y,0);
    }

    cout << endl;
    cout << "The adjacency list for the given graph is : " << endl;
    g.printedge();

    


    
    return 0;
}