#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

};


int main(){
    
    return 0;
}
class Solution {
public:
    class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };

    info solve(Node* root, int& ans) {
        // base case
        if (root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info currNode;

        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, max(left.maxi, right.maxi));
        currNode.mini = min(root->data, min(left.mini, right.mini));

        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }

        // answer update
        if (currNode.isBST) {
            ans = max(ans, currNode.size);
        }

        return currNode;
    }

    int largestBst(Node* root) {
        int maxsize = 0;
        info temp = solve(root, maxsize);
        return maxsize;
    }
};
  