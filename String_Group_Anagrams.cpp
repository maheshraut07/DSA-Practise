/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector<string>> ans;
        map <vector<int>, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            vector <int> freq(26,0);

            for(auto ch : strs[i]){   //count the frequency of each character in the string 
                freq[ch - 'a']++;
            }

            mp[freq].push_back(strs[i]);  // the frequency array of each string treated as a key for the map 
                                          // so that the string which has same characters will be pushed at the same key
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;

    }
};