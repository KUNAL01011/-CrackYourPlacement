#include <bits/stdc++.h>
using namespace std;

// Daily Temperatures
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);

    stack<int> st;

    for (int i = 0; i < temperatures.size(); i++)
    {

        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

// Minimum Cost Tree From Leaf Values
int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int s,
                  int e, vector<vector<int>> &dp)
{
    if (s >= e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];

    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}]) +
                           solveUsingMem(arr, maxi, s, i, dp) +
                           solveUsingMem(arr, maxi, i + 1, e, dp));
    }

    dp[s][e] = ans;
    return dp[s][e];
}

int solveUsingTabulation(vector<int> &arr, map<pair<int, int>, int> &maxi,
                         int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int s_index = n; s_index >= 0; s_index--)
    {
        for (int e_index = 0; e_index <= n - 1; e_index++)
        {
            if (s_index >= e_index)
            {
                continue;
            }
            int ans = INT_MAX;
            for (int i = s_index; i < e_index; i++)
            {
                ans = min(ans, (maxi[{s_index, i}] * maxi[{i + 1, e_index}]) +
                                   dp[s_index][i] + dp[i + 1][e_index]);
            }

            dp[s_index][e_index] = ans;
        }
    }
    return dp[0][n - 1];
}
int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingTabulation(arr, maxi, n);
    return ans;
}

// Online Stock Span
stack<pair<int, int>> st;

int next(int price)
{
    int span = 1;
    while (!st.empty() && st.top().first <= price)
    {
        span += st.top().second;
        st.pop();
    }
    st.push({price, span});

    return span;
}

// Rotten Oranges
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> que;
    int vis[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!que.empty())
    {
        int r = que.front().first.first;
        int c = que.front().first.second;
        int t = que.front().second;
        tm = max(tm, t);
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                que.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    // check for that vis is all 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }
    return tm;
}

int main()
{

    return 0;
}