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

// Insert a new node and return the root
TreeNode* insert(TreeNode* root, int val){
  if(!root){
    return new TreeNode(val);
  }

  if(val > root->val){
    root->right = insert(root->right, val);
  } else if(val < root->val){
    root->left = insert(root->left, val);
  }
  return root;
}

// Return the minimum value of node of the BST
TreeNode* minValue(TreeNode* root){
  TreeNode* curr = root;
  while(curr && curr-> left){
    curr = curr->left;
  }
  return curr;
}

// Remove a node and return the root of the tree
TreeNode* remove(TreeNode* root, int val)
{
    // Didn't find it
    if (!root)
        return NULL;

    // Search right
    if (val > root->val)
    {
        root->right = remove(root->right, val);
    }

    // Search left
    else if (val < root->val)
    {
        root->left = remove(root->left, val);
    }

    // Found the node
    else
    {
        // Case 1: no left child
        if (!root->left)
        {
            return root->right;
        }

        // Case 2: no right child
        else if (!root->right)
        {
            return root->left;
        }

        // Case 3: two children
        else
        {
            TreeNode* minNode = minValue(root->right);

            root->val = minNode->val;

            root->right = remove(root->right, minNode->val);
        }
    }

    return root;
}

int main() {
  return 0;
}