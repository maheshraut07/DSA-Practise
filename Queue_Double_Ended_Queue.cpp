#include<iostream>
using namespace std;
const int MAX=50;

class queue{
    int front,rear;
    int data[MAX];
    public:
    queue(){
        front=rear=-1;
    }

    void create(){
        int i,n;
        cout<<"enter the number of elements you want to create:"<<endl;
        cin>>n;
        cout<<"Enter the elements:"<<endl;
        for(i=0; i<n;i++){
            cin>>data[i];
        }
        front++;
        rear=i-1;
    }

    void display(){
        cout<<"DEqueue contains:"<<endl;
        for(int i=front; i<=rear; i++){
            cout<<data[i]<<" "<<endl;
        }
    }

    void addfront(){
        if(rear==MAX-1){
            cout<<"DEqueue is overflown"<<endl;
        }
        else{
            int x;
            cout<<"enter the value to add at the front:"<<endl;
            cin>>x;
            for(int i=rear; i>=front; i--){
                data[i+1]=data[i];
            }
            data[front]=x;
            rear++;
        }
        display();
    } 

    void addend(){
        if(rear=MAX-1){
            cout<<"DEqueue is overflown"<<endl;
        }
        else{
            int x;
            cout<<"enter the value to add at the rear:"<<endl;
            cin>>x;
            data[rear++]=x;
        }
        display();
    }

    void deleteFront(){
        if(front==-1){
            cout<<"DEqueue is underflown"<<endl;
        }
        else{
            if(front==rear){
                cout<<"deleting last element of the DEqueue"<<data[front]<<endl;
                front=rear=-1;
            }
            else{
                int item=data[front];
                cout<<"deleted element is:"<<item<<endl;
                front++;
            }
        }
        display();
    }

    void deleteEnd(){
        if(front==-1){
            cout<<"DEqueue is underflown"<<endl;
        }
        else{
            if(front==rear){
                cout<<"deleting the last element of the queue:"<<data[rear]<<endl;
                front=rear=-1;
            }
            else{
                int item=data[rear];
                cout<<"deleted element is:"<<item<<endl;
                rear--;
            }
        }
        display();
    }
};

int main(){
    queue q;
    int ch;
    do{
        cout<<"-----------MENU OF OPERATIONS-----------"<<endl;
        cout<<"1.create DEqueue"<<
            "\n2.insert  element at front"<<
            "\n3.insert element at end"<<
            "\n4.delete element from front"<<
            "\n5.delete element from rear"<<
            "\n6.Display Dequeue"<<
            "\n7.EXIT"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            q.create();
            break;

            case 2:
            int x;
            cout<<"enter the element you want to insert at front:"<<endl;
            cin>>x;
            q.addfront();
            break;

            case 3:
            cout<<"enter the element you want to insert at end:"<<endl;
            cin>>x;
            q.addend();
            break;

            case 4:
            q.deleteFront();
            break;

            case 5:
            q.deleteEnd();
            break;

            case 6:
            q.display();
            break;
            
            case 7:
            cout<<"EXITING...."<<endl;
            cout<<"Thank You"<<endl;
        }
    }
    while(ch!=7);
    return 0;
}