#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}  
  
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    
    // Initialize variables to keep track of the maximum sum and current sum
    int maxSum = INT_MIN;
    int currentSum = 0;

    // Iterate through the array using a sliding window
    for (int i = 0; i < n; ++i) {
        // If currentSum becomes negative, reset it to the current element
        if (currentSum < 0) {
            currentSum = nums[i];
        }
        // Otherwise, add the current element to the currentSum
        else {
            currentSum += nums[i];
        }

        // Update the maxSum if the currentSum is greater
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
    }