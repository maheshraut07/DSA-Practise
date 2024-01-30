#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int TotalWays(int N)
{
    const long long mod = 1e9 + 7;
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 1));

    for (int i = N - 1; i >= 0; i--)
    {
        dp[i][1] = dp[i + 1][0];

        long long make, nomake;
        make = dp[i - 1][1];
        nomake = dp[i + 1][0];

        dp[i][0] = (make + nomake) % mod;
    }

    return (dp[0][0] * dp[0][0]) % mod;
}