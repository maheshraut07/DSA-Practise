#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

pair<bool,int> isBalancedFast(Node *root){
        if(root == NULL){
            pair<bool ,int> p = make_pair(true,0);
            return p;
        }
        
        pair<int , int>  left = isBalancedFast(root -> left); 
        pair<int , int> right = isBalancedFast(root -> right);
        
        bool leftans = left.first;  // check if left node is balanaced or not
        bool rightans = right.first; // check if right node is balanced or not
        
        bool diff = abs((left.second - right.second) <= 1);
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1; // calculated the height of tree
        
        if(leftans && rightans && diff){
            ans.first = true;
        }
        else{
            ans.second = false;
        }
        
        return ans;
    }
     
    bool isBalanced(Node *root)
    {
       return isBalancedFast(root).first;
        
    }


int main(){
    return 0;
}