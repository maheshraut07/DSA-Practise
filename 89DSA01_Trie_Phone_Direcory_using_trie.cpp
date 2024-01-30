#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isterminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // root is initialized with null character
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            // check if the character of given word is terminal or not
            root->isterminal = true;
            return;
        }

        // assumption word will be in capitals
        int index = word[0] - 'a';

        TrieNode* child;

        // if first character of the word to be inserted in trie tree is present in already
        // in the trie tree then no need to create the new node for that character
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // if the first character of the word to be inserted in the trie tree is absent
        // then we have to create the new TrieNode in the Trie tree
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call for inserting all the characters present in the word
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        // function for inserting the word in the trie tree
        insertUtil(root, word);
        // TC of insertion is O(l), l = length of the word
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isterminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;

        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for lastch
            TrieNode* curr = prev->children[lastch - 'a'];

            // if not found
            if (curr == NULL) {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    // creation of Trie
    Trie* t = new Trie();

    // insert all contacts in trie
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // return ans;
    return t->getSuggestions(queryStr);
}
