#include<iostream>
using namespace std;

int main(){
    
    return 0;
}


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        
    }

};

Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow  = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    
    Node* merge(Node* left , Node* right){
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left -> data < right -> data){
                temp -> next = left ;
                temp = left;
                left = left -> next;
                
            }
            else{
                temp -> next =right;
                temp = right;
                right = right -> next;
            }
        }

        while(left != NULL || right == NULL){
                temp -> next = left ;
                temp = left;
                left = left -> next;
        }
        while(right != NULL  || left == NULL){
            temp -> next = right ;
            temp = right;
            right = right -> next;
        }    
            
        ans = ans -> next;
        return ans;    
        
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head -> next == NULL) return head;
        //find mid;
        Node* mid = findMid(head);
        
        //seperate in 2 halves
        Node* left = head;
        Node* right = mid -> next;
        mid -> next = NULL;
        
        //sort both 
        left = mergeSort(left);
        right = mergeSort(right);
        
        // merge halves
        Node* result = merge(left, right);
        
        return result;
    }