#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;    }
};

void insertAtTail(Node *&ansHead, Node *&ansTail, int data) {
    Node *temp = new Node(data);
    if (ansHead == NULL) {
        ansHead = temp;
        ansTail = temp;
    } else {
        ansTail->next = temp;
        ansTail = temp;
    }
}

Node* findIntersection(Node* head1, Node* head2) {
    unordered_map<int, int> count1, count2;  // Track the count of elements in both lists
    Node *curr = head1;

    // Count elements in the first list
    while (curr != NULL) {
        count1[curr->data]++;
        
        
        curr = curr->next;
    }

    Node *ansHead = NULL;
    Node *ansTail = NULL;
    curr = head2;

    // Iterate through the second list and find the intersection
    while (curr != NULL) {
        if (count1.find(curr->data) != count1.end() && count1[curr->data] > 0) {
            insertAtTail(ansHead, ansTail, curr->data);
            count1[curr->data]--;
        }
        curr = curr->next;
    }

    return ansHead;
}

int main(){
    
    return 0;
}