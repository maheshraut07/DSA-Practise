//recurrsion 
#include<iostream>
using namespace std;

void reachHome( int src , int dest){

    cout<<"source "<<src<<"destination "<<dest<<endl;
    if(src == dest)
    { 
    cout<<"pahuch gaya" ; //base case
    return ;
    }

               //processing
    reachHome(src++,dest);  //recurrsive relation  (tail recurrssion)
}

int main(){

    int src,dest;
    cout<<"Enter source and destination respectively: "<<endl;
    cin>>src>>dest;

    cout<<endl;

    reachHome(src,dest);

    return 0;

}
