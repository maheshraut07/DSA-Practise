#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    public:
    int firstOccu(vector<int> &arr , int n, int key){
        int s=0;
        int e=n-1;
        int ans = -1; // Initialize ans to -1 in case key is not found
        while(s<=e){
            int mid=s+(e-s)/2; // Calculate mid inside the loop
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
        }
        return ans;
    }
    int lastOccu(vector<int> &arr ,int n,int key){
        int s=0;
        int e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2; // Calculate mid inside the loop
            if(arr[mid]==key){
                ans=mid;
                s = mid +  1;   
            }
            else if ( key > arr[mid]){
                s = mid + 1;
            }
            else if ( key < arr[mid]){
                e = mid - 1;
            }}
            return ans ;
    }

       

        pair<int,int>firstAndLastPosition(vector<int>&arr,int n,int key)
        {
            pair<int,int>p;
            p.first = firstOccu(arr,n,key);
            p.second = lastOccu(arr,n,key);

            return p;
        }
         
        


};

int main(){

    BinarySearch b;
    vector<int> arr = {1,2,3,3,3,4,5};
    int n=arr.size(); // Use arr.size() to get the size of the vector
    int key=3;
    pair<int,int> p = b.firstAndLastPosition(arr,n,key);

    cout << "First and last position of the key is : " << p.first << "," << p.second;
    return 0;
}
