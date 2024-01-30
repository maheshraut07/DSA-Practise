// First non repeating character in queue

#include<bits\stdc++.h>
using namespace std;

	string FirstNonRepeating(string A){
		   queue<int> q;
		   unordered_map<char,int> map;
		   string ans = "";
		   
		   for(int i = 0; i < A.length(); i++){
		       char ch = A[i];
		       
		       map[ch]++;  // increase count
		       
		       q.push(ch);  // push in the queue
		       
		       while(!q.empty()){
		           if(map[q.front()] > 1){
		               q.pop();    // repeating character
		           }
		           else{
		               ans.push_back(q.front());  // non-repeting character
		               break;
		           }
		       }
		       
		       if(q.empty()){
		           ans.push_back('#');
		       }
		   }
		   return ans;
		}



int main(){
    
    return 0;
}