#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void depth(TreeNode* root, int d)
{
    if (root == NULL) {
        return;
    }

    cout << "Node: " << root->val
         << " Depth: " << d << endl;

    depth(root->left, d + 1);
    depth(root->right, d + 1);
}

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    depth(root, 0);

    return 0;
}