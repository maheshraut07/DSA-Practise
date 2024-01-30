#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *left;
    Node *right;
    
};


    //Function to check whether a binary tree is balanced or not.
     int height(struct Node* node){
        // code here 
        if(node == NULL) return 0;
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        int ans = max(left,right) + 1;
        return ans;
    } 
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL) return true;
        
        bool left = isBalanced(root -> left);
        bool  right = isBalanced(root -> right);
        
        bool diff = abs(height(root ->left ) - height(root -> right)) <= 1;
        
        if(left && right && diff) return true;
        else return false;
        
    }

int main(){
    
    return 0;
}


