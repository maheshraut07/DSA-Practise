/*

Unique rows in boolean matrix
Difficulty: EasyAccuracy: 48.36%Submissions: 51K+Points: 2Average Time: 15m
Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

Example 1:

Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: $1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are R1: {1 1 0 1} and R2: {1 0 0 1}. 
As R1 first appeared at row-0 and R2 appeared at row-1, in the resulting list, R1 is kept before R2.
Example 2:

Input:
row = 2, col = 4 
M[][] = {{0 0 0 1}, {0 0 0 1}}
Output: $0 0 0 1 $
Explanation: Above the matrix of size 2x4
looks like
0 0 0 1
0 0 0 1
Only unique row is $0 0 0 1 $
Your Task:
You only need to implement the given function uniqueRow(). The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix. The function should return the list of the unique row of the matrix. Do not read input, instead use the arguments given in the function.

Note: The driver code prints the rows "$" separated. You have to just return list of rows, you do not have to worry about printing anything.

Expected Time Complexity: O(row * col)
Expected Auxiliary Space: O(row * col)

Constraints:
1<=row,col<=40
0<=M[][]<=1


*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 40

// Function to get all unique rows from a binary matrix
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    set<vector<int>> seen;
    vector<vector<int>> ans;

    for (int i = 0; i < row; i++) {
        vector<int> currRow;

        // Convert row from M[][] to vector<int>
        for (int j = 0; j < col; j++) {
            currRow.push_back(M[i][j]);
        }

        // Check if this row has been seen before
        if (seen.find(currRow) == seen.end()) {
            seen.insert(currRow);          // Mark as seen
            ans.push_back(currRow);        // Add to result
        }
    }

    return ans;
}

int main()
{
    int row = 3, col = 4;
    int M[MAX][MAX] = {
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1}
    };

    vector<vector<int>> result = uniqueRow(M, row, col);

    cout << "Unique rows are:\n";
    for (auto& r : result) {
        for (int val : r) {
            cout << val << " ";
        }
        cout << "$ ";  // As per the expected format
    }

    return 0;
}


/*

🧠 Dry Run for Input:
cpp
Copy
Edit
M = {
  {1, 1, 0, 1},
  {1, 0, 0, 1},
  {1, 1, 0, 1}
}
Let’s walk through uniqueRow() step-by-step:

Step 1: i = 0
currRow = {1, 1, 0, 1}

seen is empty → currRow not found → add to seen and ans.

Now:
seen = {{1, 1, 0, 1}}

ans = {{1, 1, 0, 1}}

Step 2: i = 1
currRow = {1, 0, 0, 1}

Not in seen → add it.

Now:
seen = {{1, 1, 0, 1}, {1, 0, 0, 1}}

ans = {{1, 1, 0, 1}, {1, 0, 0, 1}}

Step 3: i = 2
currRow = {1, 1, 0, 1}

Already in seen → skip it.

✅ Final Output:
sql
Copy
Edit
Unique rows are:
1 1 0 1 $ 1 0 0 1 $
✨ Explanation Recap:
We're checking each row and using a set<vector<int>> to remember which rows we've seen.

Only new rows (not in the set) are added to the result.

This ensures order is preserved and duplicates are ignored.

Let me know if you'd like a visual diagram or want to try with another matrix!

 */