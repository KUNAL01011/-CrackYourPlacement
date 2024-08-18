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
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    int key;

    Node(int val)
    {
        this->left = left;
        this->right = right;
    }
};

// Validate Binary Search Tree
bool solve(TreeNode *root, long long int lowerBound, long long int upperBound)
{
    if (root == NULL)
        return true;

    bool cond1 = (root->val > lowerBound);
    bool cond2 = (root->val < upperBound);
    bool leftans = solve(root->left, lowerBound, root->val);
    bool rightans = solve(root->right, root->val, upperBound);

    if (cond1 && cond2 && leftans && rightans)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isValidBST(TreeNode *root)
{
    long long int lowerBound = -2147483657;
    long long int upperBound = 2147483657;

    return solve(root, lowerBound, upperBound);
}

// Binary Tree Right Side View
vector<int> rightSideView(TreeNode *root)
{
    queue<TreeNode *> q;
    if (!root)
        return {};
    vector<int> ans;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *frontNode = q.front();
        if (frontNode == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            TreeNode *temp = q.front() ? q.front() : NULL;
            if (temp == NULL)
            {
                ans.push_back(frontNode->val);
            }
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
    return ans;
}

// Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> q;
    if (!root)
        return {};
    vector<int> ans;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *frontNode = q.front();
        if (frontNode == NULL)
        {
            q.pop();
            result.push_back(ans);
            ans.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            ans.push_back(frontNode->val);
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
    return result;
}

// Path Sum III
int ans = 0;
void pathSumforOne(TreeNode *root, long long targetSum)
{
    if (!root)
        return;

    if (targetSum == root->val)
    {
        ans++;
    }

    pathSumforOne(root->left, targetSum - root->val);
    pathSumforOne(root->right, targetSum - root->val);
}
int pathSum(TreeNode *root, long long targetSum)
{
    if (root)
    {
        pathSumforOne(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }

    return ans;
}

int main()
{

    return 0;
}