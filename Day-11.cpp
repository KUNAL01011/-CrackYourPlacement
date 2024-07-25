#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

// Pattern searching
void badCharHeuristic(string str, int size,
                      int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(string txt, string pat, int &ans)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            ans = s;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

bool searchPattern(string str, string pat)
{
    // your code here
    int ans = -1;
    search(str, pat, ans);
    if (ans == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Replace O's with X's

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat,
         int delrow[], int delcol[])
{
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    // check for top right bottom left
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, vis, mat, delrow, delcol);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};

    // traverse first row and last row
    for (int j = 0; j < m; j++)
    {

        // first row
        if (!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, vis, mat, delrow, delcol);
        }

        // last row
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, vis, mat, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // first  column
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, vis, mat, delrow, delcol);
        }

        // last column
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, mat, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

// 76. Minimum Window Substring
string minWindow(string s, string t)
{
    int len1 = s.length();
    int len2 = t.length();
    int start = 0;

    if (len1 < len2)
    {
        return "";
    }

    int ansIndex = -1;
    int ansLen = INT_MAX;

    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;

    // store freq of pattern string;
    for (char ch : t)
    {
        tMap[ch]++;
    }

    // initialise variable that basically show count of actual
    // parttern wale string k char present in the currnent window
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        sMap[ch]++;
        if (sMap[ch] <= tMap[ch])
        {
            count++;
        }

        if (count == len2)
        {
            while (sMap[s[start]] > tMap[s[start]] || tMap[s[start]] == 0)
            {
                if (sMap[s[start]] > tMap[s[start]])
                {
                    sMap[s[start]]--;
                }
                start++;
            }

            int windowLength = i - start + 1;
            if (windowLength < ansLen)
            {
                ansLen = windowLength;
                ansIndex = start;
            }
        }
    }
    if (ansIndex == -1)
    {
        return "";
    }
    else
    {
        return s.substr(ansIndex, ansLen);
    }
}

// 68. Text Justification

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> ans;
    int i = 0;
    while (i < words.size())
    {
        int j = i, l = 0;
        while (j < words.size() && l + words[j].size() + (j - i) <= maxWidth)
        {
            l += words[j].size();
            j++;
        }
        string line = words[i];
        if (j - i > 1 && j < words.size())
        {
            int sp = maxWidth - l;
            int diff = sp / (j - i - 1);
            int e = sp % (j - i - 1);

            for (int k = i + 1; k < j; k++)
            {
                line += string(diff, ' ');
                if (e > 0)
                {
                    line += ' ';
                    e--;
                }
                line += words[k];
            }
        }
        else
        {
            for (int k = i + 1; k < j; k++)
            {
                line += ' ';
                line += words[k];
            }
            line += string(maxWidth - line.size(), ' ');
        }

        ans.push_back(line);
        i = j;
    }

    return ans;
}

// 115. Distinct Subsequences

int solveUsingMem(string &s, string &t, int i, int j,
                  vector<vector<int>> &dp)
{
    if (j == t.size())
        return 1;
    if (i == s.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (s[i] == t[j])
    {
        ans += solveUsingMem(s, t, i + 1, j + 1, dp);
    }
    ans += solveUsingMem(s, t, i + 1, j, dp);
    dp[i][j] = ans;
    return dp[i][j];
}
int solveUsingTabulation(string &s, string &t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++)
    {
        dp[i][t.size()] = 1;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = t.size() - 1; j >= 0; j--)
        {
            long long int ans = 0;

            if (s[i] == t[j])
            {
                ans += dp[i + 1][j + 1];
            }
            ans += dp[i + 1][j];

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}
int numDistinct(string s, string t)
{
    // vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return solveUsingTabulation(s, t);
}


int main()
{

    return 0;
}