#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element
    solve(nums, output, index + 1, ans);

    // Include the current element
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);

    // Backtrack to remove the added element
    output.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(nums, output, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> s = subsets(nums);
    
    cout << "Subsets:" << endl;
    for (const auto& subset : s) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
