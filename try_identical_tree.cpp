#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *left;
    Node *right;
};

bool isIdentical(Node *r1 , Node *r2){
    if(r1 == NULL && r2 == NULL) return true;
    else if (r1 != NULL && r2 == NULL || r1 == NULL && r2 != NULL) return false;

    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right );

    int value = r1 -> data == r2 -> data;

    if(left && right && value) return true;
    else return false;
}

int main(){
    return 0;
}