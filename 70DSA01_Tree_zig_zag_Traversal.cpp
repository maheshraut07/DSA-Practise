#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left ;
    Node *right;
};
 vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL) return result;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()){
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //level process
    	    for(int i = 0; i < size; i ++){
    	        Node *frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert
    	        
    	        int index = leftToRight ? i : size - i -1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode -> left) 
    	            q.push(frontNode -> left);
    	        
    	        if(frontNode -> right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //change the direction
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i : ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }

int main(){
    
    return 0;
}