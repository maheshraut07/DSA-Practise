#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& arr, int target, vector<int>& path, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(path); // Found a valid combination
        return;
    }
    if (target < 0) return; // Invalid path, backtrack

    for (int i = 0; i < arr.size(); i++) {
        path.push_back(arr[i]);                  // Choose
        dfs(arr, target - arr[i], path, res);    // Explore
        path.pop_back();                         // Unchoose (Backtrack)
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    vector<int> path;

    dfs(arr, target, path, res);
    return res;
}


/*

🧪 Dry Run:
Input:

cpp
Copy
Edit
arr = [1, 2]
target = 3
Initial:
res = [], path = [], target = 3

Step-by-step:

pgsql
Copy
Edit
dfs([], 3)
    choose 1 -> path = [1], target = 2
        choose 1 -> path = [1,1], target = 1
            choose 1 -> path = [1,1,1], target = 0 ✅ Add [1,1,1]
            backtrack -> path = [1,1]
            choose 2 -> path = [1,1,2], target = -1 ❌ invalid
        backtrack -> path = [1]
        choose 2 -> path = [1,2], target = 0 ✅ Add [1,2]
    backtrack -> path = []
    choose 2 -> path = [2], target = 1
        choose 1 -> path = [2,1], target = 0 ✅ Add [2,1]
        choose 2 -> path = [2,2], target = -1 ❌ invalid
✅ Final result:

cpp
Copy
Edit
[
 [1, 1, 1],
 [1, 2],
 [2, 1]
]
⏱️ Time Complexity (Worst case):
Exponential: O(k^t), where:

k is the number of elements in arr

t is the target

Because we're exploring all permutations



*/