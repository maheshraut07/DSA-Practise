#include<iostream>
using namespace std;
int calcXN(int x, int n){
    if(n == 1) return x;

    int ans = x * calcXN(x, n-1);
    return ans;

}

int main(){
    int x = 10;
    int n = 2;

    cout << "ans is :" << calcXN(x, n);

    return 0;
}