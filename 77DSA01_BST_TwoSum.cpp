
#include <bits/stdc++.h> 
using namespace std;

template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};


void inorder(BinaryTreeNode<int> * root, vector<int> &in){
    if(root == NULL) return ;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorderval;
    inorder(root, inorderval);          // we are finding inorder traversal because it is in increasing order in BST

    int i = 0;
    int j = inorderval.size() - 1;


    while(i <= j){
        int sum = inorderval[i] + inorderval[j];
        if(sum == target ) return true;
        
        else if(sum > target) j--;
        
        else i++;
    }

    return false;
}


int main(){
    
    return 0;
}

//two find two sum in a BST first find inorder traversal and push all the elements in vector of course it will be in the ascending order the find then target
// value according to the two pointer method . 




