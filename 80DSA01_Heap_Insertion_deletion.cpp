#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:

    int arr[100];
    int size ;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertMaxHeap(int val){

        size = size + 1;
        int index = size;  
        arr[index ] = val; // inserting the element at the last position of the array

        while(index > 1){

            int parent = index / 2;  // check parent val 

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;  // parent index   , updata index with parent index
            }                     // size increases during insertion 
            else{
                return ;
            }
        }

    }

    void deleteFromHeap(){
        if(size == 0) {
            cout << "Nothing to delete !!" << endl;
            return ;
        }

        //step 1 : put last element into first index
        arr[1] = arr[size];
        
        // step 2 : remove last element
        size--;

        //step 3 : take root node to its position (heapify)

        int i = 1;
        while ( i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(i <= leftIndex && arr[i] < arr[leftIndex]){   // check with leftchild 
                swap(arr[leftIndex], arr[i]);   
                i = leftIndex;                               // size decreases during deletion
            }
            else if (i <= rightIndex && arr[i] < arr[rightIndex]){  // check with right child
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;                              // size decreases during deletion
            }
            else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " " ;
        }

        cout << endl;
    }
};

void heapify(int arr[], int n , int i ){    // o(logn)
    int largest = i ;
    int left = 2 * i ;
    int right =  2 * i  + 1;

    if( left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    else if( right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n){   // o(nlogn)
    int size = n;

    while(size > 1){
         // step 1 : swap the root element with the last element;
         swap(arr[size], arr[1]);

         // step 2 : decrease the size of the array 
         size--;

         // step 3 : place the swapped element to its right position
         heapify(arr, n , 1);
    }
}

int main(){

    heap h;
    h.insertMaxHeap(50);
    h.insertMaxHeap(55);
    h.insertMaxHeap(53);
    h.insertMaxHeap(52);
    h.insertMaxHeap(54);

    h.print();
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();


    int arr[6] = {-1, 54, 53 , 55, 52 , 50};
    int n = 5;

    for(int i = n/2; i > 0 ; i--){    // we start from n/2 because after the n/2 there are all leaf elements and we dont need to apply heapify function on
                                      // leaf nodes as they are already in maxheap
        heapify(arr, n , i);          //n/2 for 1 based indxing(first element is -1)  ,  left = 2 * i, right = 2 * i + 1
    }                                 // n/2 -1 for 0 based indexing (first element is root of the maxheap) , left = 2 * i + 1, right = 2 * i + 2;

    cout << endl;
    cout << "printing the array now after hepify : " << endl;
    for(int i = 1; i <= n ; i ++){
        cout << arr[i] << " ";

    }

    cout << endl;
    cout << " printing the elements after heapsort : " << endl;
    heapsort(arr, n);

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }





    // creation of min heap and maxheap using priority queue

    //maxheap
    priority_queue<int> pq;
    
    pq.push(5);
    pq.push(4);
    pq.push(8);
    pq.push(7);

    cout << "The top elememnt in the queue is : " << pq.top() << endl;
    cout << "The size of the queue is : " << pq.size() << endl;
    pq.pop();
    cout << "The size of the queue is : " << pq.size() << endl;
    cout << " is queue is empty : " << pq.empty() << endl;

    cout << endl;

    // minheap
    priority_queue <int, vector<int> , greater<int> > minheap;

    minheap.push(5);
    minheap.push(4);
    minheap.push(8);
    minheap.push(7);

    cout << "The top elememnt in the queue is : " << minheap.top() << endl;
    cout << "The size of the queue is : " << minheap.size() << endl;
    minheap.pop();
    cout << "The size of the queue is : " << minheap.size() << endl;
    cout << " is queue is empty : " << minheap.empty() << endl;


    


    cout << endl;
    
    return 0;
     
}