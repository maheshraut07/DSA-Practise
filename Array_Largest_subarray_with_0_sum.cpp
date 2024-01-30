/*

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 int maxLen(vector<int>&A, int n) {
    unordered_map<int, int> prefixSum; // To store prefix sum and its index
    int sum = 0;
    int maxLength = 0;  // to store the maximum length of the subarray with 0 sum

    for (int i = 0; i < n; i++) {
        sum += A[i];

        if (sum == 0) {
            maxLength = i + 1;  // if we find the subarray with sum = 0 from the start postion just update the maxlength as i+1
        }
        else {
            if (prefixSum.find(sum) != prefixSum.end()) {      // if we encounter the such sum that is already present in the map that means array has subarray with 0 sum , so update the maxlength 
                maxLength = max(maxLength, i - prefixSum[sum]);  // to calculate the maxlength of two numbers => current_index- previous index
            }
            else {
                prefixSum[sum] = i;   // if we dont found the sum subarray equal to previous one just mark the entry of that subarray with current index
            }
        }
    }

    return maxLength;
}