#include <bits/stdc++.h>
using namespace std;

// K Sum Paths
void helper(Node *root, vector<int> ans, int &cnt, int k)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    helper(root->left, ans, cnt, k);
    helper(root->right, ans, cnt, k);

    // traversing the vector and chekcing if we can make the sum==k??
    int sum = 0;
    int size = ans.size();
    for (int i = size - 1; i >= 0; i--)
    {
        sum += ans[i];
        if (sum == k)
            cnt++;
    }
    ans.pop_back();
}
int sumK(Node *root, int k)
{
    // code here
    vector<int> ans;
    int cnt = 0;
    helper(root, ans, cnt, k);
    return cnt;
}

// Vertical Order Traversal of a Binary Tree
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *&node = front.first;
        auto coordinate = front.second;
        int &row = coordinate.first;
        int &col = coordinate.second;
        mp[col][row].insert(node->val);
        if (node->left)
            q.push({node->left, {row + 1, col - 1}});
        if (node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    for (auto it : mp)
    {
        auto &colMap = it.second;
        vector<int> vLine;
        for (auto colMapIt : colMap)
        {
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }

        ans.push_back(vLine);
    }

    return ans;
}

// Binary Tree Cameras
int minCameraCoverHelper(TreeNode *root, int &cam)
{
    if (root == NULL)
        return 1;

    int left = minCameraCoverHelper(root->left, cam);
    int right = minCameraCoverHelper(root->right, cam);

    if (!(left && right))
    {
        cam++;
        return 2;
    }
    return max(left, right) - 1;
}
int minCameraCover(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int cam = 0;
    if (!minCameraCoverHelper(root, cam))
        cam++;
    return cam;
}

// Sum of Distances in Tree
void dfs(vector<int> adj[], int n, int node, int prev, vector<int> &height, vector<int> &subtree)
{
    subtree[node]++;
    for (auto &ele : adj[node])
    {
        if (ele != prev)
        {
            height[ele] = 1 + height[node];
            dfs(adj, n, ele, node, height, subtree);
            subtree[node] += subtree[ele];
        }
    }
}
void rec(vector<int> adj[], int n, int node, int prev, vector<int> &subtree, vector<int> &dp)
{
    for (auto &ele : adj[node])
    {
        if (ele != prev)
        {
            dp[ele] = dp[node] - subtree[ele] + (n - subtree[ele]);
            rec(adj, n, ele, node, subtree, dp);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for (auto &ele : edges)
    {
        int u = ele[0], v = ele[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> height(n, 0), subtree(n, 0); // distance from 0 to all other nodes;
    vector<int> dp(n, 0);                    // dp[i] = sum of distances from node i to all other nodes;
    dfs(adj, n, 0, -1, height, subtree);
    for (int i = 0; i < n; i++)
        dp[0] += height[i];
    rec(adj, n, 0, -1, subtree, dp);
    return dp;
}
int main()
{

    return 0;
}