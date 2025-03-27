#include<bits/stdc++.h>
using namespace std;

// calculate the maximum sum with out adjacent
int solve(vector<int> &arr, int n, vector<int> &dp){
	    
    if(n < 0) return 0;
    if(n == 0 ) return arr[0];
    
    if(dp[n] != -1) return dp[n];
    
    int include = solve(arr, n-2,dp) + arr[n];
    int execlude = solve(arr, n-1,dp) + 0;
    
    dp[n] =  max(include,execlude);
    return dp[n];
}

int findMaxSum(vector<int>&arr, int n) {    
    // code here
    vector<int> dp (n,-1);
    int ans = solve(arr, n-1,dp );
    return ans ;
}

int main(){

    return 0;
}

// this the dynamic programmig  solution for this problem using memoization(also called as top down approach) 