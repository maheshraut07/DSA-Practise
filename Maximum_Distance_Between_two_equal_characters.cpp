#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


//approach 1;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> lastIndex;
        int maxDistance = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (lastIndex.find(ch) != lastIndex.end()) {
                int distance = i - lastIndex[ch] - 1;
                maxDistance = max(maxDistance, distance);
            } else {
                lastIndex[ch] = i;
            }
        }

        return maxDistance;
    }
};

// approach 2 

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxDistance = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            for (int j = i + 1; j < s.length(); j++) {
                char bh = s[j];
                
                if (ch == bh) {
                    int distance = j - i - 1;  // Calculate distance between equal characters
                    maxDistance = max(maxDistance, distance);
                }
            }
        }

        return maxDistance;
    }
};


