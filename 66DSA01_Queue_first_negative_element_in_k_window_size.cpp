#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    deque<long long int> dq;
    vector<long long> ans;
    
    // process first window of k size
    
    for(int  i = 0; i < K; i++){   //only negative element are inserted in the queue
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    // store answer of first k sized window 
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    
    else{
        ans.push_back(0);
    }
    
    // process for remaining windows
    
    for(int i = K; i < N; i++){
        
        // removal of front element in the queue
        if(!dq.empty() && i - dq.front() >= K ){
            dq.pop_front();
        }
        
        // addition of 1 eleement from the rear
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        // storing of ans 
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
                                                 
 }

int main(){
    return 0;
}

