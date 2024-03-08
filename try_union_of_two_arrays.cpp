#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    vector<int> ans ;

    set<int> s ;
    for(int i  : a) {
        s.insert(i);
        ans.push_back(i);
    }
    
    for(int i : b){
        if(s.find(i) == s.end())
            ans.push_back(i);
    }

    return ans ;

}

int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,4,7,1,8};

    vector<int> ans = findUnion(a,b);
    sort(ans.begin(),ans.end());

    for(int i : ans ){
        cout << i << " ";
    }

    return 0;
}