#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom ( stack <int> &s, int element){
    //base case

    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    //revcurrsive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack){
    //base case

    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recurrsive call

    reverseStack(stack);
    insertAtBottom(stack,num);
}

int main(){
    int num;
    return 0;
}