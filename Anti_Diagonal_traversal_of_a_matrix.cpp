#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    return 0;
}

vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
    int n = matrix.size();
    int N = 2 * n - 1;

    vector<vector<int>> result(N);

    // Push each element in the result vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j].push_back(matrix[i][j]);
        }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            ans.push_back(result[i][j]);
        }
    }

    return ans;
}