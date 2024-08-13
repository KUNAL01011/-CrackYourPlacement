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

// Symmetric Tree
bool isMirror(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;

    if (p && q)
    {
        if (p->val == q->val)
        {
            return (isMirror(p->left, q->right) && isMirror(p->right, q->left));
        }
    }
    return false;
}
bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}

// convert Sorted Array to Binary Search Tree
TreeNode *solve(vector<int> &nums, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = solve(nums, s, mid - 1);
    root->right = solve(nums, mid + 1, e);

    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = NULL;

    root = solve(nums, 0, nums.size() - 1);

    return root;
}

// Merge Two Binary Trees
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    if (!root2 && !root1)
        return NULL;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

// Maximum Depth of Binary Tree
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int height = max(left, right) + 1;

    return height;
}

int main()
{

    return 0;
}