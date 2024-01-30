//find out Intersection of two arrays

#include <bits/stdc++.h> 
#include<vector>
using namespace std;

int main(){
	return 0;
}
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> ans;
	int i=0, j=0;
    while(i < n && j < m ){
      if (arr1[i] == arr2[j]) {
		ans.push_back(arr1[i]);
        i++;
        j++;
      }
	  else if (arr1[i] < arr2[j] ){
		  i++;
	  }
	  else {
		  j++;
	  }
    }
	return ans; 
}