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

Node* sortedMerge(Node* head1, Node* head2)  
{  
   Node* dummy = new Node(-1);
    Node* curr = dummy;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            curr->next = new Node(head1->data);
            head1 = head1->next;
        } 
     
        else {
            curr->next = new Node(head2->data);
            head2 = head2->next;
        }
        curr = curr->next;
    }

    while (head1 != nullptr) {
        curr->next = new Node(head1->data);
        curr = curr->next;
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        curr->next = new Node(head2->data);
        curr = curr->next;
        head2 = head2->next;
    }
    
    
     
     return dummy -> next;
}  