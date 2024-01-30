#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    
    cout << "q.back() = " <<  q.back() << endl;
    
    cout << "is q.empty() = " << q.empty() << endl;
    q.emplace(60);

    int n = q.size();

    for(int i = 0; i < n; i++){
        cout << q.front() << " " ;
        q.pop();
    
    }
     

    return 0;
}