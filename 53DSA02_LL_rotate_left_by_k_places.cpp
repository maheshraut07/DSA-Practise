#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int main(){
    
    return 0;
}


    int getlength(Node *&head) {
        if (head == NULL)
        return 0;

        Node *curr = head;
        int length = 0;

        while (curr != NULL) {
            length += 1;
            curr = curr->next;
        }

        return length;
    }

    Node *rotate(Node *head, int k) {
        if (head == NULL || k == 0)
            return head;

        int length = getlength(head);
        k = k % length;

        if (k == 0)
            return head;

        Node *curr = head;
        int count = 0;
        
        while (count < k - 1 && curr != NULL) {
            count++;
            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL)
            return head;

        Node *newHead = curr->next;
        curr->next = NULL;

        Node *temp = newHead;
        
        while (temp->next != NULL)
        temp = temp->next;

        temp->next = head;

        return newHead;
}