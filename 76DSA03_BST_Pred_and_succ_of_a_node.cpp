

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    return 0;
}
    
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };




pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    //find key

    TreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    while(temp -> data != key){
        if(temp -> data > key ){
            succ = temp -> data;
            temp = temp -> left;
        }
        else{
            pred  = temp -> data;
            temp  = temp -> right;
        }
    }
    

    //pred
    TreeNode *leftTree = temp -> left;
    while(leftTree != NULL){
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }

    //succ
    TreeNode  *rightTree = temp -> right;
    while(rightTree != NULL){
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }

    pair<int , int>ans  = make_pair(pred, succ);
    return ans;




















    
}