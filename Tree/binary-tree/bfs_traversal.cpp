#include <bits/stdc++.h>
using namespace std;

/*
BFS Traversal :
1. level order traversal
*/

class TreeNode
{
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

void bfs(TreeNode *root)
{
  queue<TreeNode *> q;

  if (root)
  {
    q.push(root);
  }

  int level = 0;

  while (q.size() > 0)
  {
    cout << "Level: " << level << endl;

    int length = q.size();

    for (int i = 0; i < length; i++)
    {
      TreeNode *curr = q.front();
      q.pop();

      cout << curr->val << " ";
      if (curr->left)
      {
        q.push(curr->left);
      }
      if (curr->right)
      {
        q.push(curr->right);
      }
    }
  }
  level++;
  cout << endl;
}

int main()
{
  return 0;
}