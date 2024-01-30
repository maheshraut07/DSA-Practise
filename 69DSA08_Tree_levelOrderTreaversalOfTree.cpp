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


    vector<int> levelOrder(Node* node)
    {
      vector<int> ans;
      
      if(node == NULL) return {};
      
      queue <Node*> q;
      q.push(node);
     
      
      while(!q.empty()){
          int currNodeCount = q.size();   
          
          for(int i = 0; i < currNodeCount; i++){      // traverse all the elements at each level
              Node *curr = q.front();
              q.pop();
              
              ans.push_back(curr -> data);
              if(curr -> left ) q.push(curr -> left);          // push all the left and right elements of of the level
              if(curr -> right) q.push(curr -> right);
        }
        
      }
       return ans;
    }