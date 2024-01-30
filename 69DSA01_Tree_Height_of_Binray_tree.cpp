#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node *left;
    Node *right;
    
};
int height(struct Node* node){
        // code here 
        if(node == NULL) return 0;
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        int ans = max(left,right) + 1;
        return ans; 
    }

int main(){
    Node *node;
    return 0;
}