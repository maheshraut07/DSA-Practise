/*

122. Best Time to Buy and Sell Stock II
Solved
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solveRecu(int index, int buy, vector<int> &prices) {
        if (index >= prices.size()) return 0;

        int profit = 0;
        if (buy) { // Buy the stock
            int buykaro = -prices[index] + solveRecu(index + 1, 0, prices);
            int skipkaro = 0 + solveRecu(index + 1, 1, prices);
            profit = max(buykaro, skipkaro);
        } else { // Sell the stock
            int sellkaro = prices[index] + solveRecu(index + 1, 1, prices);
            int skipkaro = 0 + solveRecu(index + 1, 0, prices);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    int solveMemo(int index, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        if (index >= prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solveMemo(index + 1, 0, prices, dp);
            int skipkaro = 0 + solveMemo(index + 1, 1, prices, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solveMemo(index + 1, 1, prices, dp);
            int skipkaro = 0 + solveMemo(index + 1, 0, prices, dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy] = profit;
    }

    int solveTab(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buykaro = -prices[index] + dp[index + 1][0];
                    int skipkaro = 0 + dp[index + 1][1];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + dp[index + 1][1];
                    int skipkaro = 0 + dp[index + 1][0];
                    profit = max(sellkaro, skipkaro);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int solveSpace(vector<int> &prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buykaro = -prices[index] + next[0];
                    int skipkaro = 0 + next[1];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + next[1];
                    int skipkaro = 0 + next[0];
                    profit = max(sellkaro, skipkaro);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        // Uncomment the approach you want to test:

        // return solveRecu(0, 1, prices);
        
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        // return solveMemo(0, 1, prices, dp);
        
        // return solveTab(prices);

        return solveSpace(prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
