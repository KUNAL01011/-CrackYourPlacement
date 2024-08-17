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

// Binary Search Tree Iterator
class BSTIterator
{
public:
    int i = 0;
    vector<TreeNode *> ans;
    BSTIterator(TreeNode *root)
    {
        inorder(root, ans);
    }

    void inorder(TreeNode *root, vector<TreeNode *> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }

    int next()
    {
        if (i < ans.size())
        {
            return ans[i++]->val;
        }
        else
        {
            return NULL;
        }
    }

    bool hasNext()
    {
        if (i < ans.size())
        {
            return true;
        }
        return false;
    }
};
// Lowest Common Ancestor of a Binary Tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (root == p)
        return p;

    if (root == q)
        return q;

    TreeNode *LeftHand = lowestCommonAncestor(root->left, p, q);
    TreeNode *RightHand = lowestCommonAncestor(root->right, p, q);

    if (LeftHand == NULL && RightHand == NULL)
        return NULL;
    if (LeftHand != NULL && RightHand == NULL)
        return LeftHand;
    if (LeftHand == NULL && RightHand != NULL)
        return RightHand;
    return root;
}

// Unique Binary Search Trees II
map<pair<int, int>, vector<TreeNode *>> dp;
vector<TreeNode *> allPossibleBSTsMem(int start, int end)
{
    if (start > end)
        return {0};
    if (start == end)
        return {new TreeNode(start)};
    if (dp.find({start, end}) != dp.end())
        return dp[{start, end}];

    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = allPossibleBSTsMem(start, i - 1);
        vector<TreeNode *> right = allPossibleBSTsMem(i + 1, end);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return dp[{start, end}] = ans;
}
vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return {};
    return allPossibleBSTsMem(1, n);
}

// All Nodes Distance K in Binary Tree
void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
{
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> queue;
    queue.push(target);

    visited[target] = true;
    int curr_level = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        if (curr_level++ == k)
            break;

        for (int i = 0; i < size; i++)
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left] = true;
            }

            if (current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right] = true;
            }

            if (parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        result.push_back(current->val);
    }

    return result;
}

int main()
{

    return 0;
}