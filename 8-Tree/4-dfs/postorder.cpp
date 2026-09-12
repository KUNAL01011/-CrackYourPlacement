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

void postorder(TreeNode* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << endl;
}


int main() {
  return 0;
}