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
    Node *next;
    int data;
    int key;

    Node(int val)
    {
        this->left = left;
        this->right = right;
        this->next = next;
    }
};

// Construct Binary Tree from Preorder and Postorder

TreeNode *build(vector<int> &pre, int preLow, int preHigh, vector<int> &post, int postLow, int postHigh)
{
    // base case
    if (preLow > preHigh || postLow > postHigh)
        return NULL;
    TreeNode *root = new TreeNode(pre[preLow]);
    // when there is only one node
    if (preLow == preHigh)
        return root;
    int i = postLow;
    // find the 2nd element of preOrder in postOrder
    while (i <= postHigh)
    {
        if (post[i] == pre[preLow + 1])
            break;
        i++;
    }
    int leftCount = i - postLow;
    // recursion part of left & right subtree
    root->left = build(pre, preLow + 1, preLow + leftCount + 1, post, postLow, i);
    root->right = build(pre, preLow + leftCount + 2, preHigh, post, i + 1, postHigh);
    return root;
}
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();
    return build(preorder, 0, n - 1, postorder, 0, n - 1);
}


// Unique Binary Search Trees
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
int numTrees(int n)
{
    return solveTab(n);
}



// Recover Binary Search Tree
void solve(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}
void recove(TreeNode *&root, vector<int> &ans, int &i)
{
    if (!root)
        return;
    recove(root->left, ans, i);
    root->val = ans[i];
    i++;
    recove(root->right, ans, i);
}
void recoverTree(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    int i = 0;
    recove(root, ans, i);
}


// Populating Next Right Pointers in Each Node
Node *connect(Node *root)
{
    if (!root)
        return NULL;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontend = q.front();

        if (frontend == NULL)
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
            frontend->next = q.front();
            if (frontend->left)
            {
                q.push(frontend->left);
            }
            if (frontend->right)
            {
                q.push(frontend->right);
            }
        }
    }

    return root;
}

int main()
{

    return 0;
}