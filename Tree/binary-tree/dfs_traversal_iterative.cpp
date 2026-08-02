#include<bits/stdc++.h>
using namespace std;


class TreeNode {
  public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
      this->val = val;
      left = NULL;
      right = NULL;
    }
};

void inorder(TreeNode* root){
  stack<TreeNode*> st;
  TreeNode* curr = root;

  while(curr || st.size() > 0){
    if (curr) {
      st.push(curr);
      curr = curr->left;
    } else{
      curr = st.top();
      st.pop();
      cout<<curr->val<<" ";
      curr = curr->right;
    }
  }
}

void preorder(TreeNode* root){
  TreeNode* curr = root;
  stack<TreeNode*> st;

  while(curr || st.size() > 0){
    if (curr){
      cout<< curr->val<<" ";
      if(curr->right){
        st.push(curr->right);
      }
      curr = curr->left;
    }
    else {
      curr = st.top();
      st.pop();
    }
  }
}

/*
Post Order : Look the concept of the post order is we have to process left sub tree and right sub tree then process root node 

-> we can use one stack but that will give you reverse order of post order traversal that means you have reverse it so don't do this 

-> second is two stack : look the problem is when you add the root and right node of stack go left and there is a problem like sometime we pop a node we want to add his right child or sometime we pop a node we won't add his right child 

-> so there comes the second stack when we first time add the node we mark is as false and second time we mark true

*/

void postorder(TreeNode* root){
  stack<TreeNode*>st;
  stack<bool>visit;
  st.push(root);
  visit.push(false);

  while(st.size() > 0){
    TreeNode* curr = st.top();
    bool vis = visit.top();
    st.pop();
    visit.pop();

    if(curr){
      if(vis){
        cout<<curr->val<<" ";
      }
      else{
        st.push(curr);
        visit.push(true);
        st.push(curr->right);
        visit.push(false);
        st.push(curr->left);
        visit.push(false);
      }
    }
  }
}

int main() {
  return 0;
}