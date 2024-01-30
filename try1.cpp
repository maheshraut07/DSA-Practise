#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void print(Node * &head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp -> data << " ->";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){

    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* head = node1;
    head -> next = node2;
    Node* node3 = new Node(30);
    head -> next -> next = node3; 
    print(head);



    

    return 0;
}