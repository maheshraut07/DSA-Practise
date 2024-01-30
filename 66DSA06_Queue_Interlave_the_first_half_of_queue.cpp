#include<bits/stdc++.h>
using namespace std;


#include<queue>
#include<vector>
#include<stack>
class Solution{
public:

    vector<int> rearrangeQueue(queue<int> q) {
    stack<int> s;

    int n = q.size();
    int m = n / 2;
    vector<int> ans;

    while (m--) {                            // insert the first half of the queue into the stack
        int num = q.front();
        q.pop();
        s.push(num);
    }

    while (!s.empty()) {                          // insert all the elements from the stack into queue
        int num = s.top();
        s.pop();
        q.push(num);
    }

    m = n / 2;

    while (m > 0) {                                   // pop the first half of the queue and insert into the same queue
        int num = q.front();
        q.pop();
        q.push(num);
        m--;
    }

    m = n / 2; 

    while (m > 0) {                          // push the first half of the queue into stack
        int num = q.front();
        q.pop();
        s.push(num);
        m--;
    }

    while (!s.empty()) {               // till stack becomes empty pop the first element from the stack and add it in the queue then find the next element from the queue and add into the queue
        int num1 = s.top();
        s.pop();
        q.push(num1);
        ans.push_back(num1);

        int num2 = q.front();
        q.pop();
        q.push(num2);
        ans.push_back(num2);
    }

    return ans;
}
   
};

int main(){
    
    
    return 0;
}

/* 
if q = {1,2,3,4,5,6}
then ans = {1,4,2,5,3,6}*/


 