#include<bits/stdc++.h>
using namespace std;

// calculate the maximum sum with out adjacent


// this is the recurrsive solution 

int solveRecurrsive(vector<int> &arr, int n){
    if(n < 0) return 0;
    if(n == 0 ) return arr[0];
    
    int include = solveRecurrsive(arr, n-2) + arr[n];
    int execlude = solveRecurrsive(arr, n-1) + 0;
    
    return max(include,execlude);
}

// this is the dynamic programming solution using memoization

int solveMemo(vector<int> &arr, int n, vector<int> &dp){
	    
    if(n < 0) return 0;
    if(n == 0 ) return arr[0];
    
    if(dp[n] != -1) return dp[n];
    
    int include = solveMemo(arr, n-2,dp) + arr[n];
    int execlude = solveMemo(arr, n-1,dp) + 0;
    
    dp[n] =  max(include,execlude);
    return dp[n];
}

int findMaxSum(vector<int>&arr, int n) {    
    // code here

    int ansRec = solveRecurrsive(arr,n);


    vector<int> dp (n,-1);
    int ansMemo = solveMemo(arr, n-1,dp );
    return ansMemo ;
}

int main(){

    return 0;
}

// this the dynamic programmig  solution for this problem using memoization(also called as top down approach) \


/*

Important steps to covert the recurrsive solution into dynamic programming solution using memoization 

1) initialize the dp array (1d or 2d depending on the parameters ) with the values of -1 {the size of the array will depend upon the changing parameters}
2) check the result for the particular overlapping subproblems has been already computed or not if yes use it by using the syntax like in above case [ (dp[n-1] != -1) return dp[n-1]]
3) instead of returning direct result store it in a dp first 

    eg. in recurrsive solution we were returning    
            incl = something 
            exec = something 

            return max(incl,exec)

    But in the DP using memoization we use 
            
            incl = something 
            exec = something 

            dp[n] = max(incl,exec)
            retrun dp[n]
          

*/