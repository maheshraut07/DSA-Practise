/*

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int minTime(Node* root, int target) {
    unordered_map<int, vector<int>> g;
    constructGraph(root, g);

    queue<int> q;
    unordered_map<int, bool> visited;  // Change to unordered_map<int, bool>

    int timeToBurn = -1;

    q.push(target);
    visited[target] = true;

    while (!q.empty()) {   // by using the BFS
        ++timeToBurn;

        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            int currentNode = q.front();
            q.pop();

            for (int neighbor : g[currentNode]) {
                if (!visited[neighbor]) {  // Check using the unordered_map
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    return timeToBurn;
}

    
    
    
    void constructGraph(Node *root, unordered_map<int, vector<int>> &g){  
        if(!root) return ;
        
        if(root -> left){
            g[root -> data].push_back(root -> left -> data);
            g[root -> left -> data].push_back(root -> data);
        }
        
        if(root -> right){
            g[root -> data].push_back(root -> right -> data);
            g[root -> right -> data].push_back(root -> data);
        }
        
        constructGraph(root -> left, g);
        constructGraph(root -> right, g);
    }