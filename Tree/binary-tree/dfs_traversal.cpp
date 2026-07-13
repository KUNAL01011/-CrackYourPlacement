/*
DFS Traversal Has three types :
1. Inorder Traversal : [left, root, right]
2. Pre Order Traversal : [root, left, right]
3. Post Order Traversal : [left, right, root]
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

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

void preorder(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

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
