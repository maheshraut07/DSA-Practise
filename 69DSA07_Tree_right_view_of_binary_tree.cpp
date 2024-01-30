#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

vector<int> rightview(Node *root)
{
  vector<int> ans;
  if(root == NULL) return ans;
  
  queue <Node*> q;
  q.push(root);
  
  while(!q.empty()){
      int currLevelNodeCount = q.size();
      
      for(int i =  1 ; i <= currLevelNodeCount; i++){
          Node * curr = q.front();
          q.pop();
          
          if( i == currLevelNodeCount) ans.push_back(curr -> data);  // only insert in ans if that is the rightmost node
          if(curr -> left) q.push(curr -> left);
          if(curr -> right) q.push(curr -> right);
      }
  }
  
  return ans;
}
