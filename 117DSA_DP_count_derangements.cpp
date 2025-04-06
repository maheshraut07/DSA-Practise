#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long int solveRec(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    return ((n - 1) * ((solveRec(n - 1) % MOD) + (solveRec(n - 2) % MOD)) % MOD) % MOD;
}

long long int solveMemo(int n, std::vector<long long int> &dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = ((n - 1) * ((solveMemo(n - 1, dp) % MOD) + (solveMemo(n - 2, dp) % MOD)) % MOD) % MOD;
}

long long int solveTab(int n) {
    vector<long long int> dp(n + 1, -1);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {  // Fixed loop condition
        long long int  first = dp[i - 1] % MOD;
        long long int  second = dp[i - 2] % MOD;
        long long int  sum =  (first + second) % MOD;

        dp[i] = ((i - 1) * sum ) % MOD;  // Fixed formula
    }

    return dp[n];
}

long long int solveSpace(int n) {
   
    long long int prev2  = 0;
    long long int prev1  = 1;

    for (int i = 3; i <= n; i++) {  // Fixed loop condition
        long long int  first = prev2 % MOD;
        long long int  second = prev1 % MOD;
        long long int  sum =  (first + second) % MOD;

        long long int ans = ((i - 1) * sum ) % MOD;  // Fixed formula

        prev2 = prev1;
        prev1 = ans; 
    }

    return prev1;
}

long long int countDerangements(int n) {
    // return solveRec(n);

    // std::vector<long long int> dp(n + 1, -1);
    // return solveMemo(n, dp);

    // return solveTab(n);
    return solveSpace(n);
}


