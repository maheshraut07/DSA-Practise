//problem for reversing first k elements from the queue

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    
    stack <int> s;
    
    for(int i = 0; i < k; i++){  // fetch first k element in the queue and push that elements into the stack
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()) {      // fetch fist k values from the stack and push that values into the queue
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    int n = q.size() - k;
    
    while(n--){                     // pop first n elements in the queue and push that elements at the end 
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
    
    return q;
    
}

int main(){
    
    return 0;
}