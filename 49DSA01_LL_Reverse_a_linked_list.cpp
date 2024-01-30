// reverse a linked list by using iterative method
#include<iostream>
using  namespace std;

class Node
{
    public:
    Node* next;
    int data;



Node*  reverseLinkedList(Node* &head)
{   
    if(head == NULL && head -> next == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}
};

int main()
{
    Node* head;
    Node* curr;
    Node* prev;

    Node n;
    n.reverseLinkedList(head);

    return 0;


}
