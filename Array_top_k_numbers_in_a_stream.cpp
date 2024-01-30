/*

Boost your resume to top companies via this Free Hiring Contest! 

banner
Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.

In other words, you have to iterate over the array, and after each index, determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. An array will be formed for each iteration and stored in an array of arrays. If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. If two numbers have equal frequency, place the smaller number first in the array.

Example 1:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 2} 
Output: 
5 
2 5 
1 2 5 
1 2 3 5 
2 1 3 5 
Explanation:
Firstly there was 5 whose frequency
is max till now. So resulting sequence is {5}.
Then came 2, which is smaller than 5 but
their frequencies are same so resulting sequence is {2, 5}.
Then came 1, which is the smallest among all the
numbers arrived, so resulting sequence is {1, 2, 5}.
Then came 3 , so resulting sequence is {1, 2, 3, 5}
Then again 2, which has the highest
frequency among all numbers, 
so resulting sequence {2, 1, 3, 5}.
Example 2:

Input:
N=6, K=3
arr[] = {2, 1, 2, 1, 2, 1} 
Output: 
2 
1 2 
2 1 
1 2 
2 1
1 2
Explanation:
As total number of distinct values never
exceeds 2, you have to return only those two
values. In the case where frequency of 1 gets
equal with the frequency of 2, y

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


    static bool compare(pair<int,int> a, pair <int, int> b){
        if(a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    }
    
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        
        vector <vector<int>> ans;
        map <int,int> m;
        
        for(int i = 0; i < N; i++){
            if(arr[i] == 0) continue;
            
            m[arr[i]]++;
            
            vector <pair<int,int>> v;
            vector <int> curr;
            
            for(auto i : m){
                v.push_back(i);
            }
            
            sort(v.begin(), v.end(), compare);
            
            if(v.size() < K){
              for(int i = 0; i <  v.size(); i++){
                curr.push_back(v[i].first);
              }
            }
            else{
               for(int i = 0; i < K; i++){
                    curr.push_back(v[i].first);
               } 
            }
            
            
            ans.push_back(curr);
        }
        
        return ans;
    }