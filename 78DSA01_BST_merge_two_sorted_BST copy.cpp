#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    return 0;
}

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


void inorder(TreeNode *root, vector<int> &in){
    if(root == NULL) return;

    inorder(root -> left , in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            ans[k] = a[i];
            i++;
        } else {
            ans[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from a
    while (i < a.size()) {
        ans[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from b
    while (j < b.size()) {
        ans[k] = b[j];
        j++;
        k++;
    }

    return ans;
}




vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
   // step 1;
   vector<int> bst1, bst2;
   inorder(root1, bst1);
   inorder(root2, bst2);

   // merger two arayas

   vector<int> mergeArray = mergeArrays(bst1, bst2);

   return mergeArray;



}




