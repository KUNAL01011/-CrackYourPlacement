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

void preorder(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}


int main() {
  return 0;
}