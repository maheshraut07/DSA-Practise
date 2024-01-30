#include <iostream>
#define MAX 50
using namespace std;

class Stack
{

public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push()
    {
        if (size - top > 1)
        {
            int val;
            cout << " enter the value to insert into the stack: ";
            cin >> val;

            top++;
            arr[top] = val;
            return;
        }
        else
        {
            cout << "stack overflow !!!" << endl;
            return;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            cout << " element deleted : " << arr[top];
            top--;
           
        }
        else
        {
            cout << " Stack Underflow !!!" << endl;
        }
    }

    int peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << " stack is empty !!" << endl;
            return 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1) return true;
        else return false;
    }

    bool isFull()
    {
        if (top == size) return true;
        else return false;
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
        {   if( i == 0){
               cout << "|"<< arr[i]<< "|" ;
               cout << "\n|__|" << endl;
            }
            else{
               cout << "|"<< arr[i]<< "|" << endl;
            }
           
        }
        // cout << "__" << endl;
    }
};

int main()
{
    Stack st(MAX);
    int ch;
    int m;
    int choice;

    do
    {
        cout << "\n\n**********MENU**********";
        cout << "\n1.Insert Element in the stack \n2.Delete element from the stack \n3.Peek element in the stack \n4.Stack isEmpty \n5.Stack isFull \n6.Print Stack \n7.Exit ";
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            st.push();
            break;

        case 2:
            st.pop();
            break;

        case 3:
            m = st.peek();
            cout << "Top : " << m;
            break;

        case 4:
            if(st.isEmpty()){
                cout << "Stack is Empty !!" << endl;
            }
            else{
                cout << "Stack is not Empty !!" << endl;
            };
            break;

        case 5:
            if(st.isFull()){
                cout << " Stack is Full !!";
            }
            else{
                cout << "Stack is not full !!!";
            };
            break;

        case 6:
            st.print();
            break;

        case 7:
            cout << "Thank You !!!" << endl;
            exit(0);
            break;

        default:
            cout << "Invalid Choice !!!" << endl;
            break;
        }

        cout << "\n\nDo you want to continue (1/0) : ";
        cin >> choice;
    } while (choice == 1);

    cout << "Thank you !!" << endl;

    return 0;
}