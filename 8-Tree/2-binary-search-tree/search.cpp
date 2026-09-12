#include<bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val){
      this->val = val;
    }
};

bool search(TreeNode* root, int target){
  if(!root){
    return false;
  }

  if(target > root->val){
    return search(root->right, target);
  }
  else if(target < root->val){
    return search(root->left, target);
  }
  else{
    return true;
  }
}

int main() {
  return 0;
}