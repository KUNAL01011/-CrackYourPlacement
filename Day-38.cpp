#include <bits/stdc++.h>
using namespace std;

// Binary Tree Maximum Path Sum
int helper(TreeNode *node, int &ans)
{
    if (!node)
        return 0;
    int leftSum = max(0, helper(node->left, ans));
    int rightSum = max(0, helper(node->right, ans));
    ans = max(ans, node->val + leftSum + rightSum);
    return node->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}

// Binary Tree to DLL
class Solution
{
public:
    void convertToDll(Node *root, Node *&head)
    {
        if (!root)
        {
            return;
        }
        convertToDll(root->right, head);
        root->right = head;
        if (head != NULL)
        {
            head->left = root;
        }
        head = root;
        convertToDll(root->left, head);
    }
    Node *bToDLL(Node *root)
    {
        // code here
        Node *head = NULL;
        convertToDll(root, head);
        return head;
    }
};

// Preorder to BST
class Solution
{
    int i = 1;
    void create(int pre[], int size, Node *root, int min, int max)
    {
        if (i >= size || pre[i] > max)
        {
            return;
        }
        if (i < size && pre[i] > min && pre[i] < root->data)
        {
            root->left = newNode(pre[i]);
            i++;
            create(pre, size, root->left, min, root->data);
        }
        if (i < size && pre[i] > root->data && pre[i] < max)
        {
            root->right = newNode(pre[i]);
            i++;
            create(pre, size, root->right, root->data, max);
        }
    }

public:
    // Function that constructs BST from its preorder traversal.
    Node *Bst(int pre[], int size)
    {
        stack<pair<Node *, pair<int, int>>> s;
        Node *root = newNode(pre[0]);
        s.push({root, {INT_MIN, INT_MAX}});
        int i = 1;
        while (s.empty() == false)
        {
            auto p = s.top();
            Node *curr = p.first;
            int mini = p.second.first;
            int maxi = p.second.second;
            if (i < size && pre[i] > mini && pre[i] < curr->data)
            {
                curr->left = newNode(pre[i]);
                s.push({curr->left, {mini, curr->data}});
                i++;
            }
            else if (i < size && pre[i] > curr->data && pre[i] < maxi)
            {
                curr->right = newNode(pre[i]);
                s.pop();
                s.push({curr->right, {curr->data, maxi}});
                i++;
            }
            /*else if(pre[i]>maxi)
            {
                s.pop();
            }*/
            else
            {
                s.pop();
            }
        }
        return root;
    }
};

// Binary Tree Zigzag Level Order Traversal

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    bool LtoR = true;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        int width = q.size();

        vector<int> temp(width);

        for (int i = 0; i < width; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();

            int index = LtoR ? i : width - i - 1;

            temp[index] = frontNode->val;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        LtoR = !LtoR;
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}