#include<iostream>
using namespace std;

int main(){
    
    return 0;
}

struct Node {
	int val;
	struct Node* next;
	Node(int x){
		val = x;
		next = NULL;
	}
};

int getMiddleElement(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    
    while( fast && fast -> next )
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow -> val ;
}
