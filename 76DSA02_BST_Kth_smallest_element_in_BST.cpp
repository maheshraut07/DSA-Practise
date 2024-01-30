#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    return 0;
}

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };



int solve(TreeNode <int> *root, int &i, int k ){
    //base case

    if(root == NULL) return -1;

    //Left
    int left = solve(root -> left, i, k);
    
    if(left != -1) return left;

    //Node
    i++;
    if(i == k) return root -> data;

    // Right

    return solve(root -> right , i , k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int i = 0; 
    int ans = solve(root, i , k);
    return ans;
}



// Approach is simple = do inorder of it and increment counter i as it is previously set to 0, increment it till we get i == k (kth smallest)

// time complexity = o(n);
//space complexity = o(h);