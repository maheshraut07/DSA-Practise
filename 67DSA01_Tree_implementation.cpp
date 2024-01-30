#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left ;
    Node * right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node *root){
        int data;
        cout << "Enter the data: ";
        cin >> data;
        root = new Node(data);

        if(data == -1) return NULL;
        
        cout << "Enter the data for inserting in left of " << data << endl;
        root -> left = buildTree(root -> left);

        cout << "Enter the data for inserting in right of " << data << endl;
        root -> right = buildTree(root -> right);

        return root;
}


void levelOrderTraversal(Node *root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){

            // old level is treaversed so we have to enter into new level
            cout << endl; // to enter into the new level
            if(!q.empty()){
                // queue still has some child node

                q.push(NULL);
            }

        }

        else{
            cout << temp -> data << " ";
            if(temp -> left){  // if temp -> left has some value i.e not null
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }
    }
}

int height(struct Node* node){
        // code here 
        if(node == NULL) return 0;
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        int ans = max(left,right) + 1;
        return ans; 
    }


void preorder(Node *root){
    if(root == NULL) return;
    
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root){
    if(root == NULL) return;
    
    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);
}
void postorder(Node *root){
    if(root == NULL) return;
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data <<" ";
}
int main(){
    Node *root = NULL;

    // creating tree 
    root = buildTree(root);

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 

    cout << "\nPrinting the level order traversal " << endl;
    levelOrderTraversal(root);
    cout <<  endl;

    cout << "\nPreorder traversal is : " <<endl;
    preorder(root);
    cout << endl;

    cout << "\ninorder traversal is : " <<endl;
    inorder(root);
    cout << endl;

    cout << "\npostorder traversal is : " <<endl;
    postorder(root);
    cout << endl;

    int h = height(root);
    cout <<"\n Height of the given tree is : " << h;


    
    return 0;
}