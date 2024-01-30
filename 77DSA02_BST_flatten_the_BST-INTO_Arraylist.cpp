#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}



    
    
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };



void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL) return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in );
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
   vector<int>inorderVal;
   inorder(root, inorderVal);

   int n = inorderVal.size();

   TreeNode<int> * NewRoot = new TreeNode<int> (inorderVal[0]);
   TreeNode<int> * curr = NewRoot;

   for(int i = 1 ; i < n; i++){
       TreeNode<int> * temp = new TreeNode<int>(inorderVal[i]);

       curr -> left = NULL;
       curr -> right = temp;
       curr = temp;
   }

   curr -> left = NULL;
   curr -> right = NULL;

   return NewRoot;

}


/* 
Approach is simple 
1) find out the inorder traversal of the BST push the elements in the vector
2) take the first element in the bst as the root node for the list
3) make left pointer of each node as null and make the right pointer towards the next node 
4) make the left and right pointer of the last node as null */





