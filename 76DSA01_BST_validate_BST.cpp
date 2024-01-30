#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left ;
    Node *right;

};

int main(){
    return 0;
}


bool isBSt(Node *root, int min , int max){
       if(root == NULL) return true;
       
       if(root -> data > min && root -> data < max){
           bool left = isBSt(root -> left , min , root -> data);
           bool right = isBSt(root -> right , root -> data, max);
           
           return left && right;
       }
       
       else return false;
   }
   bool isBST(Node* root) {
        return isBSt(root, INT_MIN, INT_MAX);
}

//time complexity = o(n)
//space complexity = o(h)

