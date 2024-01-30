#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &maze, int n) {
    if (newx >= 0 && newx < n && newy >= 0 && newy < n && vis[newx][newy] != 1 && maze[newx][newy] == 1) {
        return true;
    } else {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &ans, vector<vector<bool>> &vis, string path) {
    // base case
    if (x == n - 1 && y == n - 1) {
        // ans.push_back(path);
        return;
    }

    // 4 movements: D, L, R, U
    vis[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, vis, maze, n)) {
        solve(x + 1, y, maze, n, ans, vis, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, vis, maze, n)) {
        solve(x, y - 1, maze, n, ans, vis, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, vis, maze, n)) {
        solve(x, y + 1, maze, n, ans, vis, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, vis, maze, n)) {
        solve(x - 1, y, maze, n, ans, vis, path + 'U');
    }

    vis[x][y] = 0;
}

vector<vector<string>> ratInAMaze(vector<vector<int>> &maze, int n) {
    vector<vector<string>> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, 0));

    string path = "";

    if (maze[0][0] == 0) return ans;

    // solve(0, 0, maze, n, ans, vis, path);
    return ans;
}

// codestudio
