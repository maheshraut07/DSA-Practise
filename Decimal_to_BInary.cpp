#include <iostream>
using namespace std;
 
void decToBinary(int n)
{
   
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{   char ch;
    do{
        cout<<"Enter the any decimal number to convert into binary : ";
        int n;
        cin>>n;
        cout<<"the equivalent binary number is : ";
        decToBinary(n);
        cout<<endl;
        cout<<endl;
        cout<<"Do you want to continue (y/n) : ";
        cin>>ch;
       
    }while( ch !='y' || ch !='n');
     return 0;
}