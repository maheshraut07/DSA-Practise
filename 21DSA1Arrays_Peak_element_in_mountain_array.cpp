//peak element in mountain array
#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>&arr){
        int s=0;
        int e=arr.size()-1;
       

        while(s<e){
            int  mid = s + (e-s)/2;

            if(arr[mid] > arr[mid+1]){
                e = mid ;

            }
            else {
                s = mid + 1 ;
            }
        }
        return s;
}

int main (){

    vector<int> arr = {1,2,3,4,6,5};

    cout << " the peak element in the mountain array is at index : " << peakIndexInMountainArray(arr); 
    return 0;
}