#include<iostream>
using namespace std;
void calcSum(int n , int i, int sum ){
    if( i == n ){
        sum += i;
        cout << "Sum is : " << sum << endl;
        return ;
    }
    
    sum += i;
    calcSum(n, i = i + 1, sum);
    cout << "stepWise sum is : " << sum  << endl;


}

int main(){
    int n = 5;

    calcSum(n, 1, 0);
    return 0;
}