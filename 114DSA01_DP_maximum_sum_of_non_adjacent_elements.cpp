#include<bits/stdc++.h>
using namespace std;

// calculate the maximum sum with out adjacent
int solve(vector<int> &arr, int n){
    if(n < 0) return 0;
    if(n == 0 ) return arr[0];
    
    int include = solve(arr, n-2) + arr[n];
    int execlude = solve(arr, n-1) + 0;
    
    return max(include,execlude);
}

int findMaxSum(vector<int>&arr, int n) {
    // code here
    
    int ans = solve(arr, n-1 );
    return ans ;
}

int main(){

    return 0;
}

// this the recurrsive solution for this problem 