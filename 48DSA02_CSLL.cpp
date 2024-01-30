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

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }

        cout <<" Memory is free for node with data "<<endl;
    }
};

void insertNode(Node* &tail){
     int val, element;
     cout << "\nEnter the value to be iserted into the List: ";
     cin >> val;
     cout <<"\nEnter the element after which you want to insert the value: ";
     cin >> element;

     //empty list
     if(tail == NULL){
        Node* newNode = new Node(val);
        tail = newNode;
        newNode -> next = newNode;
        return;
     }
    
    else{
        //Non empty list
        //assuming that the element is present in the list

        Node* curr = tail;
        while( curr -> data != element){
            curr = curr -> next;
        }

        //element found => curr is representing the node with the element;

        Node *temp = new Node(val);
        temp -> next = curr -> next;
        curr -> next = temp;
        return;
    }
}

void deleteNode(Node* &tail){
    int val;
    cout <<"Enter the value of the data to be deleted: ";
    cin >> val;

    if(tail == NULL){
        cout <<" The linked list is already empty!!!, you can't delete the element from the emepth list!!";
        return;
    }
    else{
        Node *prev = tail;
        Node *curr = prev -> next;

        while(curr -> data == val){
            prev = curr ;
            curr = curr -> next;
        }

        prev -> next = curr -> next; 

        //if there is only one node in linked list
        if(curr == prev){
            tail = NULL;
        }

        //if there are >=2 nodes
        if(tail == curr){
            tail = prev;
        }

   
        curr -> next = NULL;
        delete curr;
        return;
    }

}

bool isCircular(Node *&head){
    if(head == NULL){
        return true;
    }

    Node *temp = head -> next;
    
    while( temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }
    else{
        return false;
    }
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empty!!";
        return;
    }

    do{
        cout << tail -> data <<"->";
        tail = tail -> next;
    }while(tail != temp);

    cout << "NULL";
    cout << endl;


}

int main(){
    Node *node1 = new Node(10);
    Node* tail = node1;

    int ch;
    char choice;
    do{
        cout<<"\n\n******MENU******";
        cout<<"\n1.InsertNode\n2.deleteNode\n3.printList\n4.isCircular\n5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            insertNode(tail);
            break;
        
        case 2:
            deleteNode(tail);
            break;
            
        case 3:
            print(tail);
            break;
            
        case 4:
           if(isCircular){
            cout << " list in circular !!" << endl;
           }
           else{
            cout << " list is not circular !!" << endl;
           }
            break;

        case 5:
            cout << " Thank You!!!";
            exit(0);
            break;

        default:
            cout << " Invalid Choice!!!";
            break;
        }

        // cout << "\n do you want to continue(y/n): ";
        // cin >> choice;
    }while(ch != 5);
    return 0;
}