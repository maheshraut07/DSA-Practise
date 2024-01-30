#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2 ; k++){
               for(int l = 0; l < 2 ; l++){
                 cout<<i<<j<<k<<l<<endl;
               }
            }
        }
    }
    return 0;
}