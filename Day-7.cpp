#include <bits/stdc++.h>
using namespace std;

// 14. Longest Common Prefix
string longestCommonPrefix(vector<string> &strs)
{
    string ans;
    int i = 0;
    while (true)
    {
        char charter_count = 0;

        for (auto str : strs)
        {
            if (charter_count == 0)
            {
                charter_count = str[i];
            }

            else if (i >= str.size())
            {
                charter_count = 0;
                break;
            }

            else if (charter_count != str[i])
            {
                charter_count = 0;
                break;
            }
        }

        if (charter_count == 0)
        {
            break;
        }

        ans.push_back(charter_count);
        i++;
    }

    return ans;
}
// 680. Valid Palindrome II
bool solve(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            bool ans1 = solve(s, i + 1, j);
            bool ans2 = solve(s, i, j - 1);

            return ans1 || ans2;
        }
    }
    return true;
}

// 12. Integer to Roman
string intToRoman(int num)
{
    string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";

    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += symbol[i];
            num -= values[i];
        }
    }
    return ans;
}
// 22. Generate Parentheses
void solve(vector<string> &ans, string output, int open, int close)
{
    if (open == 0 and close == 0)
    {
        ans.push_back(output);
        return;
    }

    if (open > 0)
    {
        output.push_back('(');
        solve(ans, output, open - 1, close);
        output.pop_back();
    }

    if (close > open)
    {
        output.push_back(')');
        solve(ans, output, open, close - 1);
        output.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output;
    int open = n;
    int close = n;
    solve(ans, output, open, close);
    return ans;
}

// 71. Simplify Path
void buildans(stack<string> &st, string &ans)
{
    if (st.empty())
    {
        return;
    }
    string temp = st.top();
    st.pop();
    buildans(st, ans);
    ans += temp;
}
string simplifyPath(string path)
{
    stack<string> st;

    int i = 0;
    while (i < path.size())
    {
        int start = i;
        int end = start + 1;

        while (end < path.size() && path[end] != '/')
        {
            end++;
        }

        string minPath = path.substr(start, end - start);
        i = end;

        if (minPath == "/" || minPath == "/.")
        {
            continue;
        }

        else if (minPath != "/..")
        {
            st.push(minPath);
        }
        else if (!st.empty())
        {
            st.pop();
        }
    }

    string ans = st.empty() ? "/" : "";

    buildans(st, ans);
    return ans;
}

// 151. Reverse Words in a String
string reverseWords(string s)
{
    string ans = "";
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == ' ')
        {
            if (ans.size() != 0)
            {
                st.push(ans);
            }
            ans = "";
        }
        else
        {
            ans += s[i];
        }
    }
    if (ans.size() != 0)
    {
        st.push(ans);
    }

    s = "";
    while (!st.empty())
    {
        if (st.size() == 1)
        {
            s += st.top();
            st.pop();
        }
        else
        {
            s += st.top() + " ";
            st.pop();
        }
    }

    return s;
}
int main()
{

    return 0;
}