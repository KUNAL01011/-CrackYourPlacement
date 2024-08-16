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

// Median of BST
// Moris traversal to find the count of BST
int findCount(Node *root)
{
    int i = 0;

    Node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            i++;
            curr = curr->right;
        }

        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                i++;
                curr = curr->right;
            }
        }
    }

    return i;
}

float findActualMedian(Node *root, int n)
{
    int i = 0;
    int odd1 = (n + 1) / 2, oddVal = -1;
    int even1 = n / 2, even1Val = -1;
    int even2 = n / 2 + 1, even2Val = -1;

    Node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            i++;
            if (i == odd1)
                oddVal = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;
            curr = curr->right;
        }

        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                i++;
                if (i == odd1)
                    oddVal = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if (n & 1)
    {
        median = oddVal;
    }
    else
    {
        median = (even1Val + even2Val) / 2.0;
    }
    return median;
}

float findMedian(struct Node *root)
{
    int n = findCount(root);
    return findActualMedian(root, n);
}

// Lowest Common Ancestor of a Binary Search Tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (p->val > root->val && q->val < root->val)
    {
        return root;
    }
    return root;
}

// Predecessor and Successor

Node *inOrderSuccessor(Node *root, int x)
{
    Node *curr = root;
    Node *succ = NULL;

    while (curr)
    {
        if (curr->key > x)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    return succ;
}
Node *inOrderPredecessor(Node *root, int x)
{
    Node *curr = root;
    Node *pred = NULL;

    while (curr)
    {
        if (curr->key < x)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    return pred;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    pre = inOrderPredecessor(root, key);
    suc = inOrderSuccessor(root, key);
}

// Check whether BST contains Dead End

void solve(Node *root, unordered_map<int, bool> &visited, bool &ans)
{

    if (root == NULL)
        return;

    visited[root->data] = 1;
    if (root->left == NULL && root->right == NULL)
    {
        int xpm = root->data + 1;
        int xnm = root->data - 1 == 0 ? root->data : root->data - 1;

        if (visited.find(xpm) != visited.end() && visited.find(xnm) != visited.end())
        {
            ans = true;
            return;
        }
    }

    solve(root->left, visited, ans);
    solve(root->right, visited, ans);
}
bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int, bool> visited;
    solve(root, visited, ans);
    return ans;
}

int main()
{

    return 0;
}