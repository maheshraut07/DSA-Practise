#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Apply LIS using Binary Search
int solveOptimalWithBinarySearch(vector<int> arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back())
            ans.push_back(arr[i]);
        else {
            // Find index of just bigger element in ans
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}

// Main function to find max envelopes
int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Step 1: Sort envelopes
    // First by increasing width, if width same then decreasing height
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // Descending height
        return a[0] < b[0]; // Ascending width
    });

    // Step 2: Extract heights and apply LIS
    vector<int> heights;
    for (auto env : envelopes)
        heights.push_back(env[1]);

    return solveOptimalWithBinarySearch(heights);
}

int main() {
    vector<vector<int>> envelopes1 = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    vector<vector<int>> envelopes2 = {{1, 1}, {1, 1}, {1, 1}};

    cout << "Maximum number of envelopes (Example 1): " << maxEnvelopes(envelopes1) << endl; // Output: 3
    cout << "Maximum number of envelopes (Example 2): " << maxEnvelopes(envelopes2) << endl; // Output: 1

    return 0;
}
