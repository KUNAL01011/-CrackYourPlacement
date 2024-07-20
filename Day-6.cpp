#include <bits/stdc++.h>
using namespace std;

// 1499. Max value of Equation
int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>> p;
    int ans = INT_MIN;
    for (int i = 0; i < points.size(); i++)
    {
        while (!p.empty() && (points[i][0] - p.top().second > k))
            p.pop();
        if (!p.empty())
        {
            ans = max(ans, points[i][0] + points[i][1] + p.top().first);
        }
        p.push({points[i][1] - points[i][0], points[i][0]});
    }
    return ans;
}
// 381. Insert Delete GetRandor O(1) - Duplicates allowed
unordered_map<int, set<int>> m;
vector<int> v;

bool insert(int val)
{
    v.push_back(val);
    m[val].insert(v.size() - 1);

    if (m[val].size() == 1)
    {
        return true;
    }

    return false;
}

bool remove(int val)
{
    auto it = m.find(val);

    if (it != m.end())
    {
        auto pos = *it->second.begin();
        it->second.erase(it->second.begin());

        v[pos] = v.back();
        m[v.back()].insert(pos);
        m[v.back()].erase(v.size() - 1);

        v.pop_back();

        if (it->second.size() == 0)
        {
            m.erase(it);
        }
        return true;
    }
    return false;
}

int getRandom()
{
    return v[rand() % v.size()];
}
// 84. Largest Rectangle in Histogram
vector<int> nextSmallerelement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerelement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerelement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerelement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
// 4 . Valid Parentheses
bool isValid(string s)
{
    stack<char> st;
    if (s.size() == 1)
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch == ')' && !st.empty())
        {
            char top = st.top();

            if (top == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == '}' && !st.empty())
        {
            char top = st.top();
            if (top == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == ']' && !st.empty())
        {
            char top = st.top();
            if (top == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            st.push(ch);
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}
// 5. Print all the duplicate characters in a string
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (auto it : count)
    {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << endl;
    }
}
// 6. Find the Index of the First Occurrence in a String
int strStr(string haystack, string needle)
{
    return haystack.find(needle);
}
int main()
{

    return 0;
}