/*
Binary search 
first and last position of an element in the array*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int count=0;
        int n=nums.size();
        ans.push_back(-1);
        ans.push_back(-1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                count++;
                ans[0]=i-(count-1);
                ans[1]=i;
            }
        }
        return ans;
        
        
         
        
    }
};