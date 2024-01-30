#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}
class Solution {
public:

    int solve(vector<int> &cost, int n){

        //step 1
         vector<int> dp(n+1, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        //step2

        for(int i = 2 ; i <= n; i++){
            dp[i] = cost[i] + min (dp[i-1], dp[i-2]);
        }

        //step 3

        int ans = min(dp[1],dp[2]);
        return ans;



    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        
        int ans = solve(cost, n);
        
    }
};

// using bottom up / tabulation dp