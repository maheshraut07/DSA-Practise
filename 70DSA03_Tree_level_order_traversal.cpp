#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

};

 //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map< int, map < int, vector < int > > > nodes;  // stores horizonatal distance , level and list of  vector respecitvly
        queue < pair < Node*, pair < int, int > > > q;   // stores node, level and vector
        
        
        vector < int > ans;
        
        if(root == NULL) return ans;
        
        q.push(make_pair(root , make_pair (0,0)));
        
        while(!q.empty()){
            pair < Node*, pair<int, int> > temp = q.front();
            q.pop();
            
            Node *frontNode = temp .first;
            
            int HD = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[HD][lvl].push_back(frontNode -> data);
            
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left, make_pair(HD - 1, lvl + 1)));
            }
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right, make_pair(HD + 1, lvl + 1)));
            }
        }
        
        for(auto i : nodes){
            for(auto j : i.second){
                for(auto K : j.second){
                    ans.push_back(K);
                }
            }
        }
        
        return ans;
    }


int main(){
    
    return 0;
}