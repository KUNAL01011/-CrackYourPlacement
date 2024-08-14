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

// Minimum Absolute Difference in BST
void solve(TreeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}

int getMinimumDifference(TreeNode *root)
{
    vector<int> ans;
    int mini = INT_MAX;
    solve(root, ans);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        mini = min(ans[i + 1] - ans[i], mini);
    }

    return mini;
}

// Path Sum
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;

    targetSum = targetSum - root->val;

    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == 0)
        {
            return true;
        }
        return false;
    }

    bool left = hasPathSum(root->left, targetSum);
    bool right = hasPathSum(root->right, targetSum);

    return (left || right);
}

// Same Tree
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;

    if (p && q)
    {
        if (p->val == q->val)
        {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
    return false;
}

// Binary Tree Paths
void solve(TreeNode *root, vector<string> &ans, string output)
{
    if (root->left == NULL && root->right == NULL)
    {
        string temp = to_string(root->val);
        output += temp;
        ans.push_back(output);
        return;
    }

    string temp = to_string(root->val);
    output += temp + "->";

    if (root->left)
    {
        solve(root->left, ans, output);
    }
    if (root->right)
    {
        solve(root->right, ans, output);
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string output = "";

    solve(root, ans, output);

    return ans;
}

int main()
{

    return 0;
}