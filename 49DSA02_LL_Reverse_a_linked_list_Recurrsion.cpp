// reversing a linked list by using recurrsion

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;




void reverse( Node* & head, Node* curr, Node* prev)
{
    // base case

    if(curr == NULL)
    {
        head = prev;
        return ;
    }

    Node* forward = curr -> next;
    reverse(head , forward , curr);
}

};

int main()
{
    return 0;
}