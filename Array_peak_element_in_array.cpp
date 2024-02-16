#include<iostream>
#include<vector>

using namespace std;

int peak(vector<int>&arr){
    int s = 0;
    int e = arr.size() - 1;
    
    while(s<e){
        int mid = s + (e-s)/2;
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else {
            e = mid;
        }
    }
    return s;
}

int main(){

    vector<int> arr = {1,2,5,4,3};
    int n = peak(arr);
    cout<<"peak element in the array is : " << arr[n];
    
    return 0;
}
