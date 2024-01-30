#include<iostream>
using namespace std;

class CicularQueue{

    public:

    int *arr;
    int front;
    int rear;
    int size;

    CicularQueue(int size){
        this -> size = size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }

    void Enqueue(){
        int val;
        cout << " Enter  the element you want to insert in the queue :" << endl;
        cin >> val;

        if(front == 0 && rear == size - 1 || front == (rear -1 ) % (size - 1)){   // if queue is full 
            cout << " Queue is full !!" << endl;
        }

        else if(front == -1 ){ // queue is empty
            front = rear = 0;
            arr[rear] = val;
        }

        else if ( rear == size - 1 && front != 0){ // there is empty space reamaing at the starring and we have to insert the element at the beginning
            rear = 0;                              // to maintain cyclic nature
            arr[rear] = val;  
        }

        else{    // normal case
            rear ++;
            arr[rear] = val;
        }
    }

    void Dequeue(){
        if(front == -1){
            cout << "Queue is empty you can't pop element from the empty queue" << endl;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ // if single element is present
           front = rear = -1;
        }

        else if(front == size -1){  // if front is at the last of the queue 
            front = 0;              // to maintain cyclic  nature
        }

        front++;
        cout << "The element removed from the queue is : " << ans;
    }

};

int main(){
    return 0;