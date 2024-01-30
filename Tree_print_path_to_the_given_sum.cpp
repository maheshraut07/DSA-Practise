/*

Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path may not end on a leaf node.

Example 1:

Input : 
sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15   
        /  \     /  \
       6    7   8    9      

Output :
1 3 4
Explanation : 
Sum of path 1, 3, 4 = 8.
Example 2:

Input : 
sum = 38
Input tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15  
Explanation :
Sum of path 10, 28 = 38 and
Sum of path 10, 13, 15 = 38.

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int key;
    Node *left;
    Node *right;

    
};

int main(){
    
    return 0;
}

void dfs(Node* root, int curr_sum, vector<vector<int>> &ans, vector<int> &path, int sum) {
        if (!root) return;

        curr_sum += root->key;          // add the value of node to the curr_sum
        path.push_back(root->key);      // push the curr node into the path

        if (curr_sum == sum) ans.push_back(path);  

        dfs(root->left, curr_sum, ans, path, sum); // go deeper in left like preorder traversal
        dfs(root->right, curr_sum, ans, path, sum); // go deeper in right like preorder traversal

        path.pop_back();                   // if sum not found and node are ended pop the nodes one by one 
        curr_sum -= root -> key;
    }

    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, 0, ans, path, sum);
        return ans;
    }