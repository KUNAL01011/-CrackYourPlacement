/*
Insert in BST we have two options
1. if the target is greater the root make new root
2. or add it to right node 

-> We use second way because the add the node in leaf is easy 
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
  public :
    int val_;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val){
      val_ = val;
    }
};

TreeNode* insert(TreeNode* root, int val){
  if(!root){
    return new TreeNode(val);
  }

  if(val > root->val_){
    root-> right = insert(root->right, val);
  } else if (val < root->val_){
    root->left = insert(root->left, val);
  }

  return root;
}


/*
For Removing we have two cases 
1. the removing node has the 0 or 1 child : if the node has 0 child return NULL and if the node has one child return the child

2. the removing node has 2 child : if the node has two or more child first find the min child of the node and replace with the root and now delete the leaf node 
*/
TreeNode* minValueNode(TreeNode* root){
  TreeNode* curr = root;

  while(curr && curr->left){
    curr = curr->left;
  }
  return curr;
}

TreeNode* remove(TreeNode* root, int val){
  if(!root){
    return NULL;
  }

  if(val > root->val_){
    root->right = remove(root->right, val);
  }
  else if (val < root->val_){
    root->left = remove(root->left, val);
  }
  else {
    if (!root->left){
      return root->right;
    }
    else if(!root->right){
      return root->left;
    }
    else {
      TreeNode* minNode = minValueNode(root->right);

      root->val_ = minNode->val_;

      root->right = remove(root->right, minNode->val_);
    }
  }
  return root;
}

int main(){
  return 0;
}