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
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout << root -> data <<" " ;
            if(root -> left){
                q.push(root -> left);
            }
            if(root -> right){
                q.push(root -> right);
            }
        }
    }

}


int main(){
    Node *root = NULL;

    // creating tree 
    root = buildTree(root);

    // 1 3 7 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nPrinting the level order traversal " << endl;
    levelOrderTraversal(root);
    cout <<  endl;

    return 0;

}