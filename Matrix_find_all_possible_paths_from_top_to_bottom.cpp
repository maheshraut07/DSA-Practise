/*

Find all possible paths from top to bottom
Difficulty: EasyAccuracy: 72.55%Submissions: 11K+Points: 2Average Time: 10m
Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

Example 1:

Input: 1 2 3
       4 5 6
Output: 1 4 5 6
        1 2 5 6 
        1 2 3 6
Explanation: We can see that there are 3 
paths from the cell (0,0) to (1,2).
Example 2:

Input: 1 2
       3 4
Output: 1 2 4
        1 3 4


*/


#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int> &path, vector<vector<int>> &res) {
    path.push_back(grid[i][j]);

    if (i == n - 1 && j == m - 1) {
        res.push_back(path);
    } else {
        if (i + 1 < n)
            dfs(i + 1, j, n, m, grid, path, res);
        if (j + 1 < m)
            dfs(i, j + 1, n, m, grid, path, res);
    }

    path.pop_back();  // Backtrack
}

vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(0, 0, n, m, grid, path, res);
    return res;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> allPaths = findAllPossiblePaths(n, m, grid);

    cout << "All possible paths from top-left to bottom-right:\n";
    for (const auto &path : allPaths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}


