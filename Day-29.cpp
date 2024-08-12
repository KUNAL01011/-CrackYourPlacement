#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;


};

// Diameter of Binary Tree
int D = 0;
int heigth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = heigth(root->left);
    int rh = heigth(root->right);

    int currD = lh + rh;
    D = max(D, currD);

    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    heigth(root);
    return D;
}

// Invert Binary Tree
TreeNode *solve(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *left = root->left;
    root->left = solve(root->right);
    root->right = solve(left);

    return root;
}
TreeNode *invertTree(TreeNode *root)
{
    solve(root);
    return root;
}

// Subtree of Another Tree
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;
    if (isidentical(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

bool isidentical(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    if (a->val != b->val)
        return false;
    return isidentical(a->left, b->left) && isidentical(a->right, b->right);
}

// Range Sum of BST
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (!root)
        return 0;

    int ans = 0;
    bool wasInRange = false;

    if (root->val >= low && root->val <= high)
    {
        ans += root->val;
        wasInRange = true;
    }

    if (wasInRange)
    {
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    else if (root->val < low)
    {
        ans += rangeSumBST(root->right, low, high);
    }
    else
    {
        ans += rangeSumBST(root->left, low, high);
    }

    return ans;
}

int main()
{

    return 0;
}