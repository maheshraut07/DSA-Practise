#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & num , int n, int target){
    
    vector<int> dp(target+1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i <= target; i++){
        // trying to solve for every amount figure from 1 to target

        for(int j = 0; j < n; j++){
            if(i - num[j] >= 0 && dp[i - num[j]] != INT16_MAX){
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
            }
        }
    }

    if(dp[target] == INT_MAX) return -1;

    else return dp[target];
}

int main(){
    
    vector<int> num = {2,2,4};
    int n = num.size();
    int target = 8;

    int ans = solve(num , n, target);
    cout << "the minimum number of coins to make the target is : "<< ans; 

    return 0;
}

// This question is solved using top down dp or tabulation method  

