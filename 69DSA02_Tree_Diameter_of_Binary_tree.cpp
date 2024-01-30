#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node *left;
    Node *right;
    
};

 pair<int,int> diameterFast(Node *root){
        //base case
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root -> left);   // pair<int,int> left.first = diameter and left.second = height 
        pair<int,int> right = diameterFast(root -> right);
        
        int op1 = left.first; // diameter of left subtree
        int op2 = right.first; // diameter of right subtree
        int op3 = left.second + right.second + 1; // height of the tree
        
        pair<int ,int > ans; 
        ans.first = max(op1, max(op2,op3));    // maximum diameter 
        ans.second = max(left.second , right.second) + 1;  // maximum height in tree
        
        return ans;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast(root).first;
    }

int main(){
    
    return 0;
}