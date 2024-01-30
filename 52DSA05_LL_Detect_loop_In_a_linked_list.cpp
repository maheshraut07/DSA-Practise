#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
class solution
{
    public:
    //Function to remove a loop in the linked list.
    
    Node* floydDetect(Node *&head){
        if(head == NULL) return NULL;
        
        Node *slow = head;
        Node *fast = head;
        
        while(slow != NULL && fast != NULL){
            fast = fast -> next;
            if(fast -> next != NULL) fast = fast -> next;
            slow = slow -> next;
            
            if(slow == fast) return slow;
        }
        
        return NULL;
    }
    
    Node *getstartingNode(Node *&head){
        if(head == NULL) return NULL;
        
        Node *Intersection = floydDetect(head);
        Node *slow = head;
        
        while(slow != Intersection){
            slow = slow -> next;
            Intersection = Intersection -> next;
        }
        
        return slow;
    }
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        
        if(head == NULL) return;
        
        Node *startOfLoop = getstartingNode(head);
        Node *temp = startOfLoop;
        
        while(temp -> next != startOfLoop) temp = temp -> next;
        
        temp -> next = NULL;
            
        }
    
};

int main(){
    
    return 0;
}