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

 void collectLeafValues(TreeNode *root, vector<int> &leaf){
        if(root == NULL) return;

        if(root -> left == NULL && root -> right == NULL){
            leaf.push_back(root -> val);
        } 

        collectLeafValues(root -> left, leaf);
        collectLeafValues(root -> right, leaf);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leafValues1;
        vector<int> leafValues2;

        collectLeafValues(root1, leafValues1);
        collectLeafValues(root2, leafValues2);
        
    if(leafValues1 == leafValues2) return true;
    return false;


    }