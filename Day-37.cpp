#include <bits/stdc++.h>
using namespace std;

// Kth Smallest Element in a BST
int kthSmallest(TreeNode *root, int &k)
{
    if (root == NULL)
        return -1;

    int ans = kthSmallest(root->left, k);
    if (ans != -1)
    {
        return ans;
    }

    k--;
    if (k == 0)
    {
        return root->val;
    }

    return kthSmallest(root->right, k);
}

// Min distance between two given nodes of a Binary Tree
Node *find(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    if (root->data == a || root->data == b)
        return root;
    Node *leftAns = find(root->left, a, b);
    Node *rightAns = find(root->right, a, b);
    if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    if (rightAns != NULL && leftAns == NULL)
        return rightAns;
    if (leftAns != NULL && rightAns != NULL)
        return root;
    return NULL;
}
int finddistance(Node *root, int a, int lvl)
{
    if (root == NULL)
        return -1;
    if (root->data == a)
        return lvl;
    int left = finddistance(root->left, a, lvl + 1);
    if (left == -1)
    {
        int right = finddistance(root->right, a, lvl + 1);
        return right;
    }
    return left;
}

public:
/* Should return minimum distance between a and b
in a tree with given root*/
int findDist(Node *root, int a, int b)
{
    Node *ances = find(root, a, b);
    int nod1 = finddistance(ances, a, 0);
    int nod2 = finddistance(ances, b, 0);
    int ans = nod1 + nod2;
    if (ans < 0)
        return -1;
    return ans;
}

// Maximum Width of Binary Tree
int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    long width = 0;
    queue<pair<TreeNode *, long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        long l = q.size();
        long start = q.front().second;
        long end = q.back().second;
        width = max(width, end - start + 1);
        for (int i = 0; i < l; i++)
        {
            pair<TreeNode *, int> temp = q.front();
            q.pop();
            if (temp.first->left)
                q.push({temp.first->left, (long)2 * temp.second + 1});
            if (temp.first->right)
                q.push({temp.first->right, (long)2 * temp.second + 2});
        }
    }
    return width;
}

// 114. Flatten Binary Tree to Linked List
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            // save the right
            TreeNode *r = curr->right;
            curr->right = curr->left;
            // find the predecessor
            TreeNode *pred = curr->left;
            while (pred->right != NULL)
            {
                pred = pred->right;
            }
            // link
            pred->right = r;
            // proceeding
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    TreeNode *temp = root;
    while (temp->right != NULL)
    {
        temp->left = NULL;
        temp = temp->right;
    }
}

int main()
{

    return 0;
}