#include<bits/stdc++.h>
using namespace std;

// calculate the maximum sum with out adjacent
int solvememo(vector<int> &arr,int n , vector<int> &dp){
	    
    if(n < 0) return 0;
    if(n == 0 ) return arr[0];
    
    if(dp[n] != -1) return dp[n];
    
    int include = solvememo(arr, n-2,dp) + arr[n];
    int execlude = solvememo(arr, n-1,dp) + 0;
    
    dp[n] =  max(include,execlude);
    return dp[n];
}

int solvetab(vector<int> &arr){

    int n = arr.size();
    vector<int> dp(n,0);

    dp[0] = arr[0];

    for(int i = 1; i < n; i++){
        int include = dp[i-2] + arr[i];
        int execlude = dp[i-1] + 0;
        
        dp[i] = max(include, execlude);

    }

    return dp[n-1];


}

int solveSpaceOptimization(vector<int> &arr){

    int n = arr.size();
    
    int prev2 = 0;
    int prev1 = arr[0];

    for(int i = 1; i < n; i++){
        int include = prev2 + arr[i];
        int execlude = prev1 + 0;
        
        int ans = max(include, execlude);
        prev2 = prev1;
        prev1 = ans;

    }

    return prev1;


}



int findMaxSum(vector<int>&arr, int n) {   

    vector<int> dp(n,-1);

    int ansmemo = solvememo(arr, n-1, dp);

    int anstabu = solvetab(arr);

    return anstabu ;
}

int main(){

    return 0;
}

// this the dynamic programmig  solution for this problem using tabulizatoin(also called as bottom up approach) 