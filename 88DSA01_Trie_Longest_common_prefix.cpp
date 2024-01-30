#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // find index
        int index = word[0] - 'a';
        TrieNode* child;

        // if node is already present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // if node is absent then create a new node
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));  // Use the child node for the recursive call
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void LCP(string str, string& ans) {
        TrieNode* tempRoot = root;  // Use a temporary pointer to avoid modifying the original root

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (tempRoot->childCount == 1) {
                ans.push_back(ch);

                // traverse to the next node
                int index = ch - 'a';
                tempRoot = tempRoot->children[index];
            } else {
                break;
            }

            if (tempRoot->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie('\0');

    // insert all the strings into the trie
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string firstString = arr[0];
    string ans = "";

    t->LCP(firstString, ans);

    return ans;
}
