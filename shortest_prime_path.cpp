/*


You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
num1 = 1033 
num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach num2 from num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
num1 = 1033 
num2 = 1033
Output:
0

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

 int solve(int num1,int num2)
    {   
      vector<int> prime(10000, 1);  // for storing prime number 
     for (int i = 2; i * i < 10000; i++) {
    if (prime[i] == 1) {
        for (int j = i * i; j < 10000; j += i) {
            prime[j] = 0;  // set all multiples of i as non-prime
        }
    }
}

      
      unordered_set<int> st; 
      for(int i = 1000; i < 10000; i++){
          if(prime[i] == 1){
              st.insert(i);    // it will insert only the prime numbers into the set from 1000 to 10000
          }
      }
      
      queue<pair<int,int>> q;  // initialize the queue to store the steps and the numbers 
      q.push({0,num1});        // initially the push the 0 as the steps and given number in the queue
      
      
      while(!q.empty()){
          
          int steps = q.front().first;
          int n = q.front().second;
          q.pop();
          
          if(n == num2) return steps;   // return the step if we got our second number ;
          
          string num = to_string(n); //convert the number into string 
          
          for(int i = 0; i < 4; i++){   // because the length of the number is 4 
              for(int j = 0; j <= 9; j++){  // change every digit upt0 9 and check that is prime or not 
                  char c = num[i]; //first character in the number
                  num[i] = ('0'+j);
                  
                  int nNum = stoi(num);
                  if(st.find(nNum) != st.end()){
                      st.erase(nNum);
                      if(num2 == nNum) return steps + 1;
                      q.push({steps+1,nNum});
                  }
                  num[i] = c;
              }
          }
      }
      
      return -1;
      
      
    }