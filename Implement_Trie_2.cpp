#include<bits/stdc++.h>

using namespace std;

int main(){
    int ALPHABET_SIZE = 50;
    return 0;
}
struct TrieNode {
    TrieNode* children[50];
    bool isLeaf;

    TrieNode() {
        for (int i = 0; i < 50; i++) {
            children[i] = nullptr;
        }
        isLeaf = false;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isLeaf = true;
}

bool search(TrieNode* root, string word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) {
            return false; // Prefix not found
        }
        current = current->children[index];
    }
    return current != nullptr && current->isLeaf;
}

// this is the code for geeks for geeks