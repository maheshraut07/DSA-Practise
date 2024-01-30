#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

    int data;
    Node *right;
    Node *left;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        root -> left = insertIntoBST(root -> left, d);
    }

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

void TakeInput(Node* &root ){
    int data ;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >>data;
    }
}

Node *getmin(Node *root){
    Node *temp = root;

    while(temp -> left != NULL){
        temp = temp -> left;
    }

    return temp;
}

Node *getmax(Node *root){
    Node *temp = root;

    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp;
}

Node* delteFromBSt(Node *root, int val){
    //base case
    if(root == NULL){
        return root;   
    }

    if(root -> data == val){
        // 0 child

        if(root -> left == NULL && root ->  right == NULL){
            delete root;
            return NULL;
        }

        //1 child 
        //left child
        
        if(root -> left != NULL && root -> right == NULL){
            Node *temp = root -> left;
            delete root;
            return temp;
        }

        //right child
        if(root -> left == NULL && root -> right != NULL){
            Node *temp = root -> right;
            delete root;
            return temp;
        }


        //2 child

        if(root -> left != NULL && root -> right != NULL){
            int mini = getmin(root -> right) -> data;
            root -> data = mini;
            root -> right = delteFromBSt(root -> right , mini);
            return root;
        }
    }


}

int main(){

    Node* root = NULL;

    cout << " Enter the data to create BST " << endl;
    TakeInput(root);

    cout << "Printing the BST :" << endl;
    levelOrderTraversal(root);


    
    return 0;
}