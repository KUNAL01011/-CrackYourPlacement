#include<bits/stdc++.h>
using namespace std;

class TrieNode {
  public: 
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class Trie {
  public:
    TrieNode root;

    void insert(string word){
      TrieNode* curr = &root;
      for (char c: word){
        if(curr->children.count(c) == 0){
          curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
      }
      curr->word = true;
    }

    bool search(string word){
      TrieNode* curr = &root;
      for (char c : word){
        if(curr->children.count(c) == 0){
          return false;
        }
        curr = curr->children[c];
      }
      return curr->word;
    }

    bool startWith(string prefix){
      TrieNode* curr = &root;
      for(char c: prefix){
        if(curr->children.count(c) == 0){
          return false;
        }
        curr = curr->children[c];
      }
      return true;
    }
};



int main() {

  return 0;
}