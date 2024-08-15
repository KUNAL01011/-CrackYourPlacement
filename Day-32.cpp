#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->left = left;
        this->right = right;
        this->val = val;
    }
};

// Sum of Left Leaves
void levelOrder(TreeNode *root, int &sum)
{
    queue<TreeNode *> q;

    if (root != NULL)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        TreeNode *frontNode = q.front();

        if (frontNode == NULL)
        {
            q.pop();
        }
        else
        {
            q.pop();
            if (frontNode->left)
            {
                if (frontNode->left->left == NULL &&
                    frontNode->left->right == NULL)
                {
                    sum += frontNode->left->val;
                }
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    levelOrder(root, sum);
    return sum;
}

// Balanced Binary Tree
bool isbool = true;
int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int diff = abs(l - r);

    if (diff > 1)
    {
        isbool = false;
    }

    return max(l, r) + 1;
}
bool isBalanced(TreeNode *root)
{
    solve(root);
    return isbool;
}

// Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;

    while (curr)
    {
        // left node is NULL, then visit it and go right;
        if (curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }

        // l left node is not null
        else
        {

            // fill inorder predcessor
            TreeNode *pred = curr->left;

            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            // if pred right node is NULL, then , go left after establishing link from pred to curr;
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // left is already visited, Go right after visiting curr node,
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

// Count BST Nodes That Lie In a Given Range
void solve2(TreeNode *root, int l, int h, int &cnt)
{
    if (!root)
        return;

    solve2(root->left, l, h, cnt);
    if (root->val >= l && root->val <= h)
    {
        cnt++;
    }
    solve2(root->right, l, h, cnt);
}
int getCount(TreeNode *root, int l, int h)
{
    // your code goes here
    int cnt = 0;
    solve2(root, l, h, cnt);
    return cnt;
}

int main()
{

    return 0;
}