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
class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
     //base cases

     if(root == NULL) return 0;
     
     if(root -> data == h && root -> data == l) return 1;  // if there is only one node is present in the tree;

     //recurrsive functions
     
     if(root -> data <= h && root -> data >= l) 
        return 1 + getCount(root -> left, l , h) + getCount(root -> right, l , h);
     
     else if (root -> data < l) 
        return getCount(root -> right, l ,h);
    
     else  
        return getCount(root -> left, l , h );
    }

};