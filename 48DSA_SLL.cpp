// singly LL
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free

        if (this->next != NULL)
        {
            delete next;
            this->next == NULL;
        }

        cout << " Memory is free for node with data: " << value << endl;
    }
};
void inserthead(Node *&head)
{
    int val1;
    cout << "enter the  value which you want to insert at head :" << endl;
    cin >> val1;

    Node *temp = new Node(val1);
    temp->next = head;
    head = temp;
}
void inserttail(Node *&tail)
{
    int val2;
    cout << "enter the value you want to insert at tail :" << endl;
    cin >> val2;
    Node *temp = new Node(val2);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return;
}
void insertpos(Node *&head, Node *&tail)
{
    int val3;
    cout << "enter value which you want to insert at given position :" << endl;
    cin >> val3;

    Node *temp = new Node(val3);
    Node *prev = head;

    int position;
    cout << "enter position :" << endl;
    cin >> position;

    // Inseting at first position
    if (position == 1)
    {
        inserthead(head);
        return;
    }

    int count = 1;
    while (count < position - 1)
    {
        prev = prev->next;
        count++;
    }
    temp->next = prev->next;
    prev->next = temp;
    return;
}
void deleteNode(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    int pos;
    cout << "enter position of Node which you want to delete :" << endl;
    cin >> pos;

    // deleting first or start node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;

        // memory free to
        temp->next = NULL;
        delete temp;
        return;
    }

    int count = 1;
    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}
void reverseLinkedList(Node *&head)
{
    if (head == NULL || head -> next == NULL)
    {
        cout << head->data << " ";
        return; 
    }

    else
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
    }

    return;
}

bool isCircular(Node * &head)
    {
        if (head == NULL)
        {
            return true;
        }

        Node *temp = head->next;

        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
void print(Node *&head)
{
    Node *temp = head;
    cout << "\nLinked list is : ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{   int n ;
    cout << "Enter the value for creating the first node: ";
    cin >> n;

    cout << "\n\nNode created successfully !!! " << endl;
    cout << "Look for Menu to Proceed Further !!!!" << endl;
    Node *Node1 = new Node(n);

    Node *head = Node1;
    Node *tail = Node1;
    int ch;

    do
    {
        cout << "\n\n*****MENU*****";
        cout << "\n1.InsertAtHead\n2.InsertAtTail\n3.InsertAtPos\n4.delete\n5.display\n6.Reverse the linked list\n7..Exit" << endl;
        cout << "enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            inserthead(head);
            break;

        case 2:
            inserttail(tail);
            break;

        case 3:
            insertpos(head, tail);
            break;

        case 4:
            deleteNode(head);
            break;

        case 5:
            print(head);
            break;

        case 6:
            reverseLinkedList(head);
            break;

        case 7:
            exit(0);
            cout << "THANK YOU!!!!!!";
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    } while (ch != 7);
    return 0;
}