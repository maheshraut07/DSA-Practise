#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    return 0;
}

 int kthSmallest(int arr[], int l, int r, int k) {
    std::priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++) {
       
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}