#include <bits/stdc++.h>
using namespace std;

// 273. Integer to English Words
vector<pair<int, string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string numberToWords(int num)
{
    // base case
    if (num == 0)
    {
        return "Zero";
    }

    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }
            string b = it.second;
            string c = "";
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }
            return a + b + c;
        }
    }
    return " ";
}

// 65. Valid Number
enum STATE
{
    INIT,
    I1,
    I2,
    I3,
    I4,
    I5,
    S1,
    S2,
    S3
};

bool isNum(char ch)
{
    return ch >= 48 && ch <= 57;
}

class Solution
{
public:
    bool isTrueState(STATE s)
    {
        return s == S1 || s == S2 || s == S3;
    }

    bool isNumber(string s)
    {
        STATE curr = INIT;

        for (int i = 0; i < s.length(); i++)
        {
            if (curr == INIT && (s[i] == '+' || s[i] == '-'))
            {
                curr = I1;
            }
            else if (curr == INIT && isNum(s[i]))
            {
                curr = S1;
            }
            else if (curr == INIT && s[i] == '.')
            {
                curr = I2;
            }
            else if (curr == I1 && isNum(s[i]))
            {
                curr = S1;
            }
            else if (curr == I1 && s[i] == '.')
            {
                curr = I2;
            }
            else if (curr == S1 && (s[i] == 'e' || s[i] == 'E'))
            {
                curr = I3;
            }
            else if (curr == S1 && s[i] == '.')
            {
                curr = S2;
            }
            else if (curr == S1 && isNum(s[i]))
            {
                curr = S1;
            }
            else if (curr == I2 && isNum(s[i]))
            {
                curr = S2;
            }
            else if (curr == I3 && isNum(s[i]))
            {
                curr = S3;
            }
            else if (curr == I3 && (s[i] == '+' || s[i] == '-'))
            {
                curr = I5;
            }
            else if (curr == S2 && (s[i] == 'e' || s[i] == 'E'))
            {
                curr = I4;
            }
            else if (curr == S2 && isNum(s[i]))
            {
                curr = S2;
            }
            else if (curr == I4 && isNum(s[i]))
            {
                curr = S3;
            }
            else if (curr == I4 && (s[i] == '+' || s[i] == '-'))
            {
                curr = I5;
            }
            else if (curr == I5 && isNum(s[i]))
            {
                curr = S3;
            }
            else if (curr == S3 && isNum(s[i]))
            {
                curr = S3;
            }
            else
            {
                return false;
            }
        }

        return isTrueState(curr);
    }
};

// Word Wrap
int dp[505][2005];
int rec(int i, int rem, vector<int> &arr, int &k)
{
    if (i == arr.size())
    {
        return 0;
    }
    if (dp[i][rem] != -1)
    {
        return dp[i][rem];
    }

    int ans;
    if (arr[i] > rem)
    {
        ans = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);
    }
    else
    {
        int choice1 = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);
        int choice2 = rec(i + 1, rem - arr[i] - 1, arr, k);
        ans = min(choice1, choice2);
    }
    dp[i][rem] = ans;

    return dp[i][rem];
}
int solveWordWrap(vector<int> nums, int k)
{
    // Code here
    memset(dp, -1, sizeof(dp));
    return rec(0, k, nums, k);
}

// Smallest window in a string containing all the characters of another string
string smallestWindow(string s, string p)
{
    // Your code here
    vector<int> freq(256, 0);
    for (int i = 0; i < p.size(); i++)
    {
        freq[p[i]]++;
    };

    int n = s.size();
    int m = p.size();
    int right = 0;
    int left = 0;
    int required = m;
    int minLen = INT_MAX;
    int minStart = 0;

    while (right < n)
    {
        if (freq[s[right]] > 0)
        {
            required--;
        }
        freq[s[right]]--;

        while (required == 0)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                minStart = left;
            }
            freq[s[left]]++;
            if (freq[s[left]] > 0)
                required++;
            left++;
        }
        right++;
    }

    return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
}

int main()
{

    return 0;
}