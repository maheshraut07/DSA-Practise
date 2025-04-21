/*

123. Best Time to Buy and Sell Stock III
Solved
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solveRecu(int index, int buy, int limit, vector<int>& prices) {
        if (index >= prices.size() || limit == 0) return 0;

        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solveRecu(index + 1, 0, limit, prices);
            int skipkaro = solveRecu(index + 1, 1, limit, prices);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solveRecu(index + 1, 1, limit - 1, prices);
            int skipkaro = solveRecu(index + 1, 0, limit, prices);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    int solveMemo(int index, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (index >= prices.size() || limit == 0) return 0;

        if (dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solveMemo(index + 1, 0, limit, prices, dp);
            int skipkaro = solveMemo(index + 1, 1, limit, prices, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solveMemo(index + 1, 1, limit - 1, prices, dp);
            int skipkaro = solveMemo(index + 1, 0, limit, prices, dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buykaro = -prices[index] + dp[index + 1][0][limit];
                        int skipkaro = dp[index + 1][1][limit];
                        profit = max(buykaro, skipkaro);
                    } else {
                        int sellkaro = prices[index] + dp[index + 1][1][limit - 1];
                        int skipkaro = dp[index + 1][0][limit];
                        profit = max(sellkaro, skipkaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int solveSpace(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buykaro = -prices[index] + ahead[0][limit];
                        int skipkaro = ahead[1][limit];
                        profit = max(buykaro, skipkaro);
                    } else {
                        int sellkaro = prices[index] + ahead[1][limit - 1];
                        int skipkaro = ahead[0][limit];
                        profit = max(sellkaro, skipkaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            ahead = curr;
        }

        return ahead[1][2];
    }

    int maxProfit(vector<int>& prices) {
        // Uncomment one of the approaches to test:

        // return solveRecu(0, 1, 2, prices);
        
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveMemo(0, 1, 2, prices, dp);
        
        // return solveTab(prices);
        
        return solveSpace(prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4}; // Example input
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
