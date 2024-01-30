 #include<iostream>
 using namespace std;
 
 int main(){
    
    return 0;
 }
 struct  node{
    public:
    int data;
    node *next;

 }
 
 struct node *reverseIt(struct node *head, int k) {
        if (head == NULL)
        return NULL;

        struct node *prev = NULL;
        struct node *curr = head;
        struct node *forward = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward != NULL) {
            head->next = reverseIt(forward, k);
        }

        return prev;
    }
