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

void bfs(TreeNode* root){
  queue<TreeNode*> queue;
  if(root){
    queue.push(root);
  }

  int level = 0;

  while(queue.size() > 0){
    cout<< "Level : "<<level<<endl;
    int len = queue.size();
    for(int i = 0; i < len; i++){
      TreeNode* curr = queue.front();
      queue.pop();

      cout<<curr->val<<" ";
      if(curr->left){
        queue.push(curr->left);
      }
      if(curr->right){
        queue.push(curr->right);
      }
    }
    level++;
    cout<<endl;
  }
}


int main() {
  return 0;
}