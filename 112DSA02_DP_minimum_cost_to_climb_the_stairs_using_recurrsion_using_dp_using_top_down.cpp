#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}
class Solution {
public:

    int solve(vector<int> &cost, int n, vector<int> &dp ){

        //base case

        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        //step3

        if(dp[n] != -1) return dp[n];


        //step2
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2,dp));
        return dp[n];


    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        //create dp array with initial values as -1
        //step 1 

        vector<int> dp(n+1, -1);

        int ans = min(solve(cost, n-1,dp) , solve(cost, n-2,dp));
        return ans;
        
    }
};

//using top down dp