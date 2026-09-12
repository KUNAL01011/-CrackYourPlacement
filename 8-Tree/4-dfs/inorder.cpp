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

void inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}


int main() {
  return 0;
}