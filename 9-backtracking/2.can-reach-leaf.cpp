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
bool canReachLeaf(TreeNode* root, vector<int>&path){
  if(!root || !root->val == 0){
    return false;
  }
  path.push_back(root->val);
  if(!root->left && !root->right){
    return true;
  }

  if(canReachLeaf(root->left, path)){
    return true;
  }
  if(canReachLeaf(root->right, path)){
    return true;
  }
  path.pop_back();
  return false;
}

int main() {
  return 0;
}