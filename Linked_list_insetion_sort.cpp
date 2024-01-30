#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Node{
    public:

    int data;
    Node *next;

    Node(int d);
};

 Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* dummy = new Node(1000);
        
        while(head_ref != NULL){
            Node* forward = head_ref -> next;
            Node* temp = dummy;
            
            while(temp -> next!=NULL && temp -> next -> data < head_ref -> data){
                temp = temp -> next;
            }
            head_ref -> next = temp -> next;
            temp -> next = head_ref;
            head_ref = forward;
        }
        return dummy -> next;
    }

