#include<iostream>
using namespace std;

int main(){
    
    return 0;
}


struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

};
class Solution
{
    public:
    
    Node* detectLoop(Node* &head){    // floyd detection algorithm
        if(head == NULL) return NULL;
        
        Node *fast = head;
        Node *slow = head;
        
        while(slow != NULL && fast != NULL){
            fast = fast -> next;
            if(fast != NULL) fast = fast -> next;
            
            slow = slow -> next;
            if(slow == fast) return slow;
        }
        
        return NULL;
    }

};