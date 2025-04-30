/*

LEETCODE 

Code
Testcase
Test Result
Test Result
188. Best Time to Buy and Sell Stock IV
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solveSpace(vector<int>& prices, int k) {
        int n = prices.size();
        // Instead of 3D DP, use two 2D arrays of size 2 x (k+1)
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
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

        return ahead[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        return solveSpace(prices, k);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    cout << "Maximum Profit: " << sol.maxProfit(k, prices) << endl;
    return 0;
}
