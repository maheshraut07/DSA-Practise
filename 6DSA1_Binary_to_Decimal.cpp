//BInary to decimal 

#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter  any Binary Number:  ";
    cin>>n;

    int ans = 0;
    int i = 0;
    
    while(n != 0){
        int digit = n % 10;

       if(digit == 1){
        ans  = ans + pow(2, i);
       } 
       n = n/10;
       i++;
    }

    cout<<"Answer is : "<<ans;
   
   return 0;
}


/*

2nd method using for loop 


#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n ;
    cout << "enter any binary number of your choice : ";
    cin >> n;
    cout << endl;
    
    int ans = 0;
    
    for(int i = 0; n != 0; i++){
        int digit = n % 10;
        
        cout << "digit is : " << digit << endl;
        if(digit == 1){
            ans += pow(2,i);
        }
         cout << "ans is : " << ans << endl;
        n /= 10;
        cout << "the value of i is : " << i << endl;
        cout << endl;
    }
    
    cout << "final answer is : " << ans;
    return 0;
}

*/