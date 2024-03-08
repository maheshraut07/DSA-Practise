//Pointers 
#include<iostream>
using namespace std;

int main(){
    int arr[10]={23,122,41,67};
     
     cout<<"the address of the first element in the array is :" <<arr<<endl;
     cout<<"the address of the first element in the array is :" <<&arr<<endl;
     cout<<"the address of the first element in the array is :"<<&arr[0]<<endl;

     cout<<*arr <<endl;   //23
     cout<<*arr+1<<endl;  //23+1 = 24
     cout<<*(arr+1)<<endl; //122  arr[i]=*(arr+i)
     cout<<*(arr)+1<<endl;       
     cout<<arr[2]<<endl;         //arr=*arr[0]
     cout<<*(arr+2)<<endl; //41

     int i=3;
     cout<<i[arr]<<endl; //67


     int temp[10]={1,2};
     cout<<sizeof(temp)<<endl;//40

     int *ptr = &temp[0];
     cout<<sizeof(ptr)<<endl; //4
     cout<<sizeof(*ptr)<<endl; //4
     cout<<sizeof(&ptr)<<endl;//4


     int a[20] = {1,2,3,5};
     cout<<&a[0]<<endl;//address
     cout<<&a<<endl;//address
     cout<<a<<endl;//address

     int *p=&a[0];
     cout<<p<<endl;  //address
     cout<<*p<<endl; //1
     cout<<&p<<endl; //address


    

     cout<<"before  "<<p<<endl;
     p = p+1;
     cout<<"after  "<<p<<endl;
    return 0;



    
}