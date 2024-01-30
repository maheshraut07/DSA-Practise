// return substraction of product and sum of a number 

#include<iostream>
using namespace std;

class Solution {
public:
    void subtractProductAndSum(int n) { 
        int prod = 1;
        int sum = 0; 

        while(n != 0){
            int digit = n % 10;
            prod = prod * digit;
            sum = sum + digit;
            n = n / 10;
        }
        cout<< prod-sum;
    }
};
int main(){

    Solution s; 
    int a ; 
    cout<<"Enter any number: ";
    cin >>a;

    s.subtractProductAndSum(a);
    return 0; 
}