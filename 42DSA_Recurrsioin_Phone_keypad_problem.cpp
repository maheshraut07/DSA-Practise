/*phone keypad problem
given  a string containing digits from  2 to 9 inclusive , return all 
possible letter combinations that the number could represent . Return the answer 
in any order 
a mapping of diigits to letters just like on the telephone buttons is given 
note that 1 does not map to any letters */


#include<iostream>
#include<vector>
using namespace std;

void solve( string digit, string output, int index, vector<string>&ans, string mapping[]){
    
    if(index >= digit.length()){      //base case
        ans.push_back(output);
        return ;
    }

    int number = digit[index]-'0';
    string value = mapping[number];
    
    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digit, output, index+1, ans, mapping);
        output.pop_back();
    }
    
    }

vector<string> letterCombinations(string digits){
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = { "", "", "abc", "def", "ghi", "jkl","mno",
                           "pqrs","tuv","wxyz"};
    solve(digits, output, index, ans , mapping);
    return ans;
}
int main(){
  
    string digits = "23";

    vector <string> my = letterCombinations(digits);
    for(auto i : my){
        cout<<i<<" ";
    }

      return 0; 
}

//output will be 
// output = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
