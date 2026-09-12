#include<bits/stdc++.h>
using namespace std;

class TreeNode {
  public: 
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(int val){
      this->val = val;
    }
};
// Determine if a path exists from the root of the tree to a leaf  node it may not contain any zero
bool canReachLeaf(TreeNode* root){
  if(!root || !root->val == 0){
    return false;
  }
  if(!root->left && !root->right){
    return true;
  }

  if(canReachLeaf(root->left)){
    return true;
  }
  if(canReachLeaf(root->right)){
    return true;
  }
  return false;
}

int main() {
  return 0;
}