#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

string FirstNonRepeating(string A){
		    
		    
		    unordered_map<char ,int> count;
		    queue <char> q;
		    string ans = "";
		    
		    for(int i = 0; i < A.size(); i++){
		        
		        char ch = A[i];  
		        
		        count[ch] ++;   // determine the count of each character
		        
		        q.push(ch);     // push that character in the queue
		        
		        while(!q.empty()){
		            
		            char ch1 = q.front();
		            
		            if(count[ch1] > 1) // if it is the repeating character pop from the queue
		                q.pop();        // because we need the non repeating character
		                
		            else{              // found non repeating character
		                
		                ans.push_back(ch1); // insert the non repeating character in the ans
		                break;              // break the loop
		            }
		         
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');   // if non repeating character  is not found  the simply push the #
		        }
		    }
		    
		    return ans;
		}


/*

/GFG


Example 1:

Input: A = "aabc"
Output: "a#bb"   
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'


in first example first non repeating characters are b and c but b comes first so it is the answer
*/