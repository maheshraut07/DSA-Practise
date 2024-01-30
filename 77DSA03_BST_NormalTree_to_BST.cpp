#include<iostream>
#include<vector>
using namespace std;

 template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };


int main(){
    return 0;
}
void inorder(TreeNode<int> *root, vector<int> &in){
    if(root == NULL) return;

    inorder(root -> left , in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

TreeNode<int> * inorderToBST(int s , int e,  vector<int> in){
    if(s > e) 
        return NULL;

    int mid = (s +e) /2;

    TreeNode<int> *root = new TreeNode<int>(in[mid]);
    root -> left = inorderToBST(s, mid-1, in);
    root -> right = inorderToBST(mid + 1,  e, in);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector <int> inorderval;
    inorder(root, inorderval);
    TreeNode<int> * Root = inorderToBST(0, inorderval.size()-1, inorderval);
    return Root;


}

/*
TO Convert Noraml tree into BSt is simple
1) fetch the inorder of the given tree
2) push the inorder traversal into vector
3) find the middle element of the tree , made it root node , left part of the middle element becomes left tree and right part of the middle 
   elements become the right tree and do it recurrsively .*/

