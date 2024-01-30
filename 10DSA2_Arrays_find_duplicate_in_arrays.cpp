/*  find duplicate in the array
ie. 1,2,3,4,5,3  in this array 3 is unique
*/
#include<iostream>
#include<vector>
using namespace std;

void findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int ans = 0;

    // xor all array elements 
    for(int i = 0; i < arr.size(); i++){
        ans = ans ^ arr[i];
        cout<<ans<<endl;
    }

	
    // xor [1, n-1]
    cout<<endl;
    cout<<endl;
    for(int i = 1; i < arr.size(); i++){
        ans = ans ^ i;
        cout<<ans<<endl;
    }

    cout<<"\nduplicate  element is :"<<ans;
}
int main(){
    vector<int> arr= {1,2,3,4,5,3};
    findDuplicate(arr);
    return 0;
}  

