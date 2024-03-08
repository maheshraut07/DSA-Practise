#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    
    
    
    void solve(stack<int> &s, int count, int sizeOfStack){
        if(count == sizeOfStack/2){
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        solve(s,count+1, sizeOfStack);
        
        s.push(num);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        solve(s,0,sizeOfStack);
        
        
    }
    
};

int main(){
    stack<int> s;
    
    return 0;
}