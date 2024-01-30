#include<iostream>
using namespace std;
class Node{
    public:
    int data = 5;
    Node* next;

    Node(int d){
        cout<<"\nvalue of this : "<<this<<endl;
        cout <<"value of this : "<<this->data<<endl;
        cout<<"value of d :" << d << endl;
    }
};

int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);


    return 0;
}