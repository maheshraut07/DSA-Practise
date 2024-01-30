#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Node{
    public:
    int data;
    Node *next;
};

Node* solve(Node* node1, Node* node2) {
    Node* curr1 = node1;
    Node* forward1 = curr1->next;

    Node* curr2 = node2;
    Node* forward2 = curr2->next;

    while (forward1 != NULL && curr2 != NULL) {

        if ((curr2->data >= curr1->data) && (curr2->data <= forward1->data)) {
            curr1->next = curr2;
            forward2 = curr2->next;
            curr2->next = forward1;
            curr1 = curr2;
            curr2 = forward2;
        }
        else if (curr2->data < curr1->data) {
            curr2->next = curr1;
            node1 = curr2;
            curr1 = node1;
            forward1 = curr1->next;
            curr2 = forward2;
        }
        else {
            curr1 = forward1;
            forward1 = forward1->next;

            if (forward1 == NULL) {
                curr1->next = curr2;
                return node1;
            }
        }
    }
    node1 = reverse(node1);
    return node1;
}

Node* reverse(Node*& node1) {
    if (node1 == NULL || node1->next == NULL) return node1;

    Node* prev = NULL;
    Node* curr = node1;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    node1 = prev;
    return node1;
}

Node* mergeResult(Node* node1, Node* node2) {
    if (node1 == NULL) return node2;
    if (node2 == NULL) return node1;

    if (node1->data <= node2->data) {
        node1 = solve(node1, node2);
        reverse(node1);  // Reverse the merged list
        return node1;
    } else {
        node2 = solve(node2, node1);
        reverse(node2);  // Reverse the merged list
        return node2;
    }
}
