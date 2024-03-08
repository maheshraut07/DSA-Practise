#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

struct node *reverseIt(struct node *head, int k) {
    if (head == NULL)
        return NULL;

    struct node *prev = NULL;
    struct node *curr = head;
    struct node *forward = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL) {
        head->next = reverseIt(forward, k);
    }

    return prev;
}

int main() {
    struct node *head = new node();
    struct node *second = new node();
    struct node *third = new node();
    struct node *fourth = new node();
    struct node *fifth = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = NULL;

    int k = 2; // Group size
    head = reverseIt(head, k);

    cout << "Reversed Linked List:" << endl;
    struct node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
