//check the power of two
#include<math.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 int ans = 0;
    void isPowerOfTwo(int n) {
        for(int i = 0; i <= 30; i ++){
            int ans = pow(2, i);
            if(ans == n){
                cout<<"n is the power of two"<<endl;
                return ;
            }
           

        }
        cout<<"n is not the power of two";
        
    }
};

int main(){
    Solution s ;
    int n ;
    cout<<"enter the value of n: ";
    cin>>n;

    s.isPowerOfTwo(n);

    // if(var){
    //     cout<<"the number is power of two"<<endl;
    // }
    // else{
    //     cout<<"the number is not the power of two"<<endl;
    // }
   return 0;

}