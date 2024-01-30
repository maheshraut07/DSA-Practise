#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int value = this -> data;

        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout <<"Memory is free for node with data : " << value;
    }
};

void inserthead(Node *&head)
{
    if (head == NULL)
    {
        Node *temp = new Node(10);
        head = temp;
        return;
    }
    else
    {
        int val;
        cout << "Enter the value to insert at head: ";
        cin >> val;

        Node *temp = new Node(val);

        temp->next = head;
        head->prev = temp;
        head = temp;

        return;
    }
}

void inserttail(Node *&tail)
{
    if (tail == NULL)
    {
        Node *temp = new Node(10);
        tail = temp;
        return;
    }
    else
    {
        int val;
        cout << "Enter the value to be inserted at tail: ";
        cin >> val;

        Node *temp = new Node(val);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;

        return;
    }
}
void insertpos(Node *&head, Node *&tail)
{
    int val, pos, cnt = 1;
    cout << "Enter the value to be inserted at any position: ";
    cin >> val;

    cout << " Enter the position at which you want to insert the value: ";
    cin >> pos;

    Node *temp = head;

    // if position is first or at start
    if (pos == 1)
    {
        inserthead(head);
        return;
    }

    //Insert at last position
    if(temp -> next == NULL){
        inserttail(tail);
        return;
    }

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *NodeaToInsert = new Node(val);

    NodeaToInsert->next = temp->next;
    temp->next->prev = NodeaToInsert;
    temp->next = NodeaToInsert;
    NodeaToInsert->prev = temp;
}
void deleteNode(Node* &head){
    int pos;
    cout<<"enter the postion from which you want to delete the node: ";
    cin >> pos;

    if(pos == 1){

        Node* temp = head;

        temp -> next -> prev = NULL;
        head = temp -> next;
        head -> prev = NULL;

        delete temp;
    }

    else{
        //deleting any middle or last node

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next =  curr -> next;
        curr -> next = NULL;

        delete curr;
    }

}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
    return;
}

int main()
{
    Node *Node1 = new Node(10);

    Node *head = Node1;
    Node *tail = Node1;


    int ch;

    do
    {
        cout<<"\n\n*****MENU*****";
        cout<<"\n1.InsertAtHead\n2.InsertAtTail\n3.InsertAtPos\n4.delete\n5.display\n6.Exit"<<endl;
        cout<<"enter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            inserthead(head);
            break;

        case 2:
            inserttail(tail);
            break;

        case 3:
            insertpos(head , tail);
            break;

        case 4:
            deleteNode(head);
            break;

        case 5:
            print(head);
            break;

        case 6:
            exit(0);
            cout<<"THANK YOU!!!!!!";
            break;
        default:
            cout<<"Invalid choice";
            break;
        }
    }
     while (ch!=6);
    return 0;
}