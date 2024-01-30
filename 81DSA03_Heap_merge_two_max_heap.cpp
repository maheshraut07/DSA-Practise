#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    return 0;
}

 
    void heapify(vector<int> &arr, int n , int i ){
        
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n && arr[largest] < arr[left]) largest = left;
        if(right < n && arr[largest] < arr[right]) largest = right;
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
        
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
     // step 1 : merge two vector first
        vector<int> ans;
        for(auto i  : a)
            ans.push_back(i);
        for(auto i : b)
            ans.push_back(i);
            
     // step 2 : heapify the resultant vector
     
     int size = ans.size();
     for(int i = size/2 - 1; i >= 0 ; i --){
         heapify(ans, size, i);
     }
     
     return ans;
    }

/*
Approach is simple 
1) copy the elements in both the heaps in a vector
2) apply the heapify function on the resultant vector

** time complexity is o(m+n)*/