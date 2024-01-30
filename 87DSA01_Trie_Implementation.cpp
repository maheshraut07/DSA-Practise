#include<iostream>
using namespace std;


class TrieNode{

    public:
    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch){
        data = ch;

        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }

        isterminal = false;
    }

};


class Trie{

    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('\0'); // root is initialized with null character
    }

    void insertUtil(TrieNode *root, string word){
           // base case
            if(word.length() == 0){            // check if the character of givern word is terminal or not 
                root -> isterminal = true;
                return;
            }

            //assumption word will be in capitals
            int index = word[0] = 'A';  

            TrieNode* child;

            // if fist character of the word to be insertd in trie tree is present in already 
            // in the trie tree then no need to create the new node for that character

            if(root -> children[index] != NULL){
                child = root -> children[index];
            }
            
            // if the first character of the word to be inserted in the trie tree is absent 
            // then we have to create the new TrieNode in the Trie tree
            else{
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            // Recurrsive call for inserting all the characters present in the word

            insertUtil(child, word.substr(1));  // word.substr(1) means the next word for recurrsie call start from the charater except the first character
    }

    void insertWord(string word){     // function for inserting the word in the trie tree
        insertUtil(root, word);       // TC of insertion in O(l) l = length of the word
    }


    bool searchUtil(TrieNode* root, string word){
        // base case
        // if last char of word is terminal then required word is found

        if(word.length() == 0){
            return root -> isterminal;
        }

        int index = word[0] - 'A';   // index will return the ascii value of the char of the word to be inserted
        TrieNode *child;

        // if node is present 
        // then do nothing and go next to find the next word
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        // if node is absent 
        // then simply that word is not present 
        else{
            return false;
        }

        //Recurrsion
        return searchUtil(child, word.substr(1));
    }

    
    bool search(string word){
        searchUtil(root, word);    // TC O(l) l = length of the word 
    }

};


int main(){

    Trie *t = new Trie();
    t -> insertWord("abcd");


    
    return 0;
}