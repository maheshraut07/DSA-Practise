/*permutation of string
Given an array of nums of distinct integers , return all the possible
permutations . you can return the answer in any order*/

#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int> nums , vector<vector<int>>&ans , int index){

    if(index >= nums.size()){    //base case
        ans.push_back(nums);
        return ;
    }

    for(int j=0; j<nums.size(); j++){
        swap(nums[index] , nums[j]);
        solve(nums, ans , index+1);

        // backtrack
        swap(nums[index], nums[j]);

    }
}


vector<vector<int>> permute(<vector<int>>&nums){
    vecotr<vector<int>> ans;
    int index = 0;
    solve(nums, ans , index);
    return ans;
}

int main(){
    vector<int> nums = [1,2,3]
    return 0;
}


// output will be = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]