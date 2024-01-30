#include<iostream>
using namespace std;

class Kqueue{
    public:
    int n, k;   // n is the size of arrray and k is the number of queue we have to implement;
    int *arr;   // for implementing the queue 
    int *next;  //for storing free index for inserting the element;
    int *front; // for storing all the indexes of front of all the queues
    int *rear;  // for storing all the indexes of rear of all the queues
    int index;  // for inserting the element at this index
    int freespot ; // for storing the index of the next free spot

    Kqueue(int n , int k){
        this -> n = n;
        this -> k = k;

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        
        for(int i = 0; i < k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < n; i++){
            next[i] = i + 1;
        }

        freespot = 0;
    }

    void enqueue(int data, int qn){
        // overflow

        if(freespot == -1) {
            cout << "No empty space is available for inserting the element in the queue " << endl;
            return;
        }

        // find first free index;

        int index = freespot;

        // update freespot
        freespot = next[index];

        //check whether we are inserting first element or not
        if(front[qn - 1] == -1){
            front[qn -1 ] = index;
        }
        else{
            // link new element to the previous element 
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[n-1] = index;

        // push element 
        arr[index] = data;

    }

    int dequeue(int qn){
        //underflow
        if(front[qn -1] == -1){
            cout << "queue Underflow " << endl;
            return -1;
        }

        //find the index to pop
        int index = front[qn-1];

        // increment front
        front[qn-1] = next[index];

        //manage freespot
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
    


};


int main(){
    
    Kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    // cout << q.dequeue(1) << endl;

    // cout << q.dequeue(1) << endl;

    return 0;
}