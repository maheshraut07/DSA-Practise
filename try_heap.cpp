#include<iostream>
using namespace std;

class heap{

    public:
    int arr[100];
    
    int size;

    heap(){
        size = 0;
    }


    void insertInMaxHeap(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(size > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index  = parent;
            }
            else{
                return;
            }
        }

    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main(){

    heap h;
    h.insertInMaxHeap(50);
    h.insertInMaxHeap(55);
    h.insertInMaxHeap(53);
    h.insertInMaxHeap(52);
    h.insertInMaxHeap(54);
    

    h.print();
    
    return 0;
}