/*
LEETCODE 



Code
Testcase
Test Result
Test Result
801. Minimum Swaps To Make Sequences Increasing
Hard
Topics
Companies
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
Example 2:

Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1
 

Constraints:

2 <= nums1.length <= 105
nums2.length == nums1.length
0 <= nums1[i], nums2[i] <= 2 * 105


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solveRecu(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        if(index >= nums1.size()) return 0;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped){
            swap(prev1, prev2);
        }

        int ans = INT_MAX;

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveRecu(nums1, nums2, index + 1, 0);
        }

        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solveRecu(nums1, nums2, index + 1, 1));
        }

        return ans;
    }

    int solveMemo(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        if(index >= nums1.size()) return 0;

        if(dp[index][swapped] != -1) return dp[index][swapped];

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped){
            swap(prev1, prev2);
        }

        int ans = INT_MAX;

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveMemo(nums1, nums2, index + 1, 0, dp);
        }

        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solveMemo(nums1, nums2, index + 1, 1, dp));
        }

        return dp[index][swapped] = ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n - 1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if(swapped){
                    swap(prev1, prev2);
                }

                int ans = INT_MAX;

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = dp[index + 1][0];
                }

                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1 + dp[index + 1][1]);
                }

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int solveSpace(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index = n - 1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if(swapped){
                    swap(prev1, prev2);
                }

                int ans = INT_MAX;

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = next[0];
                }

                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1 + next[1]);
                }

                curr[swapped] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int solveSpace2(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int Swap = 0; 
        int noSwap = 0; 
        int currSwap = 0; 
        int currNoSwap = 0; 

        for(int index = n - 1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if(swapped){
                    swap(prev1, prev2);
                }

                int ans = INT_MAX;

                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = Swap;
                }

                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1 + Swap);
                }
                if(swapped) currSwap = ans; 
                else currNoSwap = ans ; 
                
            }

            Swap = currSwap;
            noSwap = currNoSwap; 
            
        }

        return min(Swap, noSwap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = 0;
        int index = 1;
        int n = nums1.size();

        // return solveRecu(nums1, nums2, index, swapped);

        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveMemo(nums1, nums2, index, swapped, dp);

        // return solveTab(nums1, nums2);

        return solveSpace(nums1, nums2);
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};

    Solution sol;
    int result = sol.minSwap(nums1, nums2);

    cout << "Minimum swaps needed: " << result << endl;
    return 0;
}
