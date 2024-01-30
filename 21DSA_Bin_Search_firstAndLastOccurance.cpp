//first and last position in the sorted array using binary search
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    public:
    int firstOccu(int arr[] , int n, int key){
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        int ans;
        while(s<=e){
            if(arr[mid]==key){
                ans=mid;
                e=mid-1;
            }
            else if(key>arr[mid]){
                s=mid+1;
            }
            else if(key<arr[mid]){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    int lastOccu(int arr[],int n,int key){
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(arr[mid]==key){
                ans=mid;
                s = mid +  1;   
            }
            else if ( key > arr[mid]){
                s = mid + 1;
            }
            else if ( key < arr[mid]){
                e = mid - 1;
            }
       

        pair<int,int>firstAndLastPosition(vector<int>&arr,int n,int key)
        {
            pair<int,int>p;
            p.first = firstOccu(arr,n,key);
            p.second = lastOccu(arr,n,key);

            return p;
        }
         return ans ;
        
}
}
};

int main(){

    BinarySearch b;
    int arr[7]={1,2,3,3,3,4,5};  
    int n=sizeof(arr);
    int key=3;
    b.firstOccu( arr ,n,key);
    b.lastOccu( arr,n,key);
    return 0;
}