#include <iostream>
#include <vector>

using namespace std;

int maxSumInWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    int windowSum = 0;

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;

    // Slide the window through the array
    for (int i = k; i < n; i++) {
        // Add the current element to the window sum
        windowSum += nums[i];

        // Subtract the element going out of the window
        windowSum -= nums[i - k];

        // Update the maximum sum if needed
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, 2, 3, -10, -3};
    int k = 4;

    int result = maxSumInWindow(nums, k);

    cout << "Maximum sum of subarray with size at least " << k << ": " << result << endl;

    return 0;
}

// sliding window
