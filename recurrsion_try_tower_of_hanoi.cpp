#include<iostream>
using namespace std;

void towerOfHanoi(int n , string src, string help , string dest){
    if(n == 1){
        cout << "disk " << n << " is transferred from " << src << " to " << dest << endl;
        return ;
    }
    
    towerOfHanoi(n - 1, src, dest, help);
    cout << "disk " << n << " is transferred from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, help, src, dest);

}

int main(){
    towerOfHanoi(2, "S","H","D");
    return 0;
}