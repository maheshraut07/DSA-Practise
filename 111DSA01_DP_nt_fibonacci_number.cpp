#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){
    // Base case
    //step1
    if(n <= 1) return n;

    // Memoization: if the value is already computed, return it
    //step3
    if(dp[n] != -1) return dp[n];

    // Recursive calculation and memoization
    //step2
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    // Step 1: Create a vector to store computed values (memoization)
    vector<int> dp(n+1);

    // Initialize the vector with -1 to indicate that values are not computed yet
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    // Output the Fibonacci number for the given input
    cout << fib(n, dp) << endl;
}

//using top down dp
