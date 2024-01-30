#include<iostream>
#define MAX 50;
using namespace std;

class Queue{
    public:

    int *arr;
    int front;
    int rear;
    int size;

    Queue(){
        this -> size = MAX;
        arr = new int[size];
        front = 0;
        rear = 0;
       }

    void EnQueue(){
        int value;
        cout << "Enter the value of the element to be inserted in the queue: ";
        cin >> value;

        if(rear == size){
            cout << "Queue is full you can't insert the value in the queue !!!" << endl;
        }

        else{
            arr[rear] = value;
            rear ++;
        }
    }

    void DeQueue(){
        if(front == rear){
            cout << "Queue is empty you cant't delete the element from the queue !!!" << endl;
            front = rear = 0;
        }

        else{
            int element = arr[front];
            cout << " element deleted : " << element;
            front ++;
        }
    }

    void Front(){
        if(front == rear){
            cout << " Queue is Empty !!" << endl;
        }
        else{
            cout << "front element is : " << arr[front] << endl;
            
        }
    }

    void Last(){
        if(front == rear){
            cout << "Queue is empty !!";
            front = rear = 0;
            
        }
        else{
            int element = arr[rear - 1 ];
            cout << "Last element in the queue is : " << element;
        }
    }

    bool isEmpty(){
        if(front == rear){
            front = rear = 0;
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isFull(){
        if(rear == size){
            return 1;
        }
        else{
            return 0;
        }
    }

    void print(){
        for(int i  = front ; i < rear; i++){
            cout <<  arr[i] << " ";
        }
    }
};

int main(){
    Queue q;
    int ch;

    do{
        cout << "\n\n*************MENU****************";
        cout << "\n1.insert element \n2.delete element\n3.front element\n4.last element\n5.isEmpty\n6.isFull\n7.Print\n8.Exit\n"<<endl;
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch(ch){
            case 1:
                q.EnQueue();
                break;
            
            case 2:
                q.DeQueue();
                break;

            case 3:
                q.Front();
                break;

            case 4:
                q.Last();
                break;
            
            case 5:
                if(q.isEmpty()){
                    cout << "Queue is Empty !!" << endl;
                }
                else {
                    cout << "Queue is not Empty !!" << endl;
                }
                break;

            case 6: 
                if(q.isFull()){
                    cout << "Queue id full !!!" << endl;
                }
                else{
                    cout << "Queue is not full!!!" << endl;
                }
                break;
            
            case 7: 
                cout << "The Queue is : ";
                q.print();
                break;

            case 8:
                cout << "Thank You !!!" << endl;
                exit(0);
                break;

            default:
                cout << "Invalid Choice !!!" << endl;
                
        } 
    }while(ch != 8);


    return 0;
}