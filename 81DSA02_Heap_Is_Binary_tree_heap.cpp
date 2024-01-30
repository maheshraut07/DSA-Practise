#include<iostream>
using namespace std;

int main(){
    
    return 0;
}

class Node{
    public:
    int data;
    Node *left;
    Node *right;

};

int countNodes(struct Node* root){
        if(root == NULL) return 0;
        
        int ans = 1 + countNodes(root -> left) + countNodes(root  -> right);
        return ans;
    }
    
    bool isCBT(struct Node* tree , int index, int totalCount){
        
        if( tree == NULL) return true;
        if(index >= totalCount) return false;
        
        else{
            bool left = isCBT(tree -> left , 2 * index + 1 , totalCount );
            bool right = isCBT(tree -> right, 2 * index +2 , totalCount);
            
            return (left && right);
        }
        
    }
    
    bool ismaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL) return true;
        
        if(root -> right == NULL) return root -> data > root -> left -> data;
        
        else{
            bool left = ismaxOrder(root -> left);
            bool right = ismaxOrder(root -> right );
            
            return (left && right && (root -> data > root -> left -> data && root -> data > root -> right -> data));
        }
        
        
    }
    
    
    bool isHeap(struct Node* tree) {
        
        int index = 0;
        int totalCount = countNodes(tree);
        
        if(isCBT(tree, index, totalCount) && ismaxOrder(tree)) return true;
        else return false;
    }


// Time complexity of this question is o(n);

/*
Approach for this question is 
1} find out that heap  is CBT or not 
2) find out that the heap follow maxheap propety or not
3) check whether both the conditions are true or not */