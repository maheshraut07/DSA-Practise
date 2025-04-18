/*
GFG _ Longest arithmetic subsequence 
Given a set of numbers, find the Length of the Longest Geometrix Progression (LLGP) that can be formed using the elements of the set in any order. The common ratio of GP must be an integer.


Example 1:

Input:
N = 3
arr = {2, 4, 3}
Output: 2
Explaination: The longest geometric
progression is {2, 4}.

Example 2:

Input:
N = 6
Arr = {5, 7, 15, 10, 20, 29}
Output: 3
Explaination: The longest geometric 
progression is {5, 10, 20}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function lenOfLongestGP() which takes the array arr[] and its size N as input parameters and returns the Length of the Longest Geometrix Progression (LLGP).


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solveRecu(int index, int diff, vector<int> &arr) {
        // base case for backward check 
        if(index < 0) return 0;

        int ans = 0; 
        for(int i = index - 1; i >= 0; i--) {
            if(arr[index] - arr[i] == diff) {
                ans = max(ans, 1 + solveRecu(i, diff, arr));
            }
        }

        return ans; 
    }

    int solveMemo(int index, int diff, vector<int> &arr, unordered_map<int, int> dp[]) {
        if(index < 0) return 0;

        if(dp[index].count(diff)) return dp[index][diff];

        int ans = 0; 
        for(int i = index - 1; i >= 0; i--) {
            if(arr[index] - arr[i] == diff) {
                ans = max(ans, 1 + solveMemo(i, diff, arr, dp));
            }
        }

        return dp[index][diff] = ans; 
    }

    int longestArithSeqLength(vector<int>& nums) {
        vector<int> arr = nums;
        int n = arr.size();
        if(n <= 2) return n; 

        int ans = 0;
        unordered_map<int, int> dp[n+1];

        for(int i = 0 ; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = arr[j] - arr[i];
                ans = max(ans, 2 + solveMemo(i, diff, arr, dp));
                // If you want to test without memoization:
                // ans = max(ans, 2 + solveRecu(i, diff, arr));
            }
        }

        return ans; 
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 7, 10, 13, 14, 19};
    vector<int> arr2 = {2, 4, 6, 8, 10};

    cout << "Length of Longest Arithmetic Progression in arr1: " 
         << sol.longestArithSeqLength(arr1) << endl;

    cout << "Length of Longest Arithmetic Progression in arr2: " 
         << sol.longestArithSeqLength(arr2) << endl;

    return 0;
}
