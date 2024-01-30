#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        isterminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, std::string word) {
        // base case
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, std::string word) {
        // base case
        if (word.length() == 0) {
            return root->isterminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode* root, std::string word) {
        // base case
        if (word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // Recursive call
        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};


// This is the code studio code



