#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        set<int>S;
        for (auto it = m.begin(); it != m.end(); it++) {
            int occu = it->second;

            if (S.find(occu) != S.end()) {
                return false;
            }

            S.insert(occu);
        }

        return true;
    }
};
