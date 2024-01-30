#include<bits/stdc++.h>

using namespace std;

int main(){
    
    return 0;
}

   long long minCost(long long arr[], long long n) {
       
       priority_queue<long long , vector<long long> , greater<long long >> pq;
       
      for(int i = 0; i < n ; i++){
          pq.push(arr[i]);
      }
       
       long long  cost = 0;
       
       while(pq.size() > 1){
           long long a = pq.top();
           pq.pop();
           
           long long b = pq.top();
           pq.pop();
           
           long long sum = a + b;
           cost += sum;
           
           pq.push(sum);
       }
       
       return cost;
    }

    // vector is given , question is that find out the two minimun two elements from the array and add both the elements add it to cost and again push them in queue
    /*
    Approach is simple 
    1) use minheap */