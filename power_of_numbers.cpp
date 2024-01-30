#include<iostream>
using namespace std;

int main(){
    
    return 0;
}

class Solution{
    public:
    //You need to complete this fucntion
    
  long long power(int N, int R) {
    long long result = 1;
    long long base = N;
    long long mod = 1000000007;

    while (R > 0) {
        if (R % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        R /= 2;
    }

    return result;
}


};