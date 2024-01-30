#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

 void constructGraph(TreeNode* root) {

        unordered_map<int, vector<int>> graph;
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }

    /*
    its like preorder
    1) processing 
    2) visit left
    3) visit right*/