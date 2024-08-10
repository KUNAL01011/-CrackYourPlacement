#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
struct petrolPump
{
    int petrol;
    int distance;
};
// Remove All Adjacent Duplicates in String II
string removeDuplicates(string s, int k)
{
    vector<pair<char, int>> st;

    for (char c : s)
    {
        if (st.empty() || st.back().first != c)
        {
            st.push_back({c, 1});
        }
        else
        {
            st.back().second++;

            if (st.back().second == k)
            {
                st.pop_back();
            }
        }
    }

    string ans = "";

    for (auto ele : st)
    {
        ans.append(ele.second, ele.first);
    }

    return ans;
}

// Evaluate Reverse Polish Notation
int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (auto s : tokens)
    {
        if (s == "+")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a + b);
        }
        else if (s == "-")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        }
        else if (s == "*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a * b);
        }
        else if (s == "/")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b / a);
        }
        else
        {
            st.push(stoi(s));
        }
        cout << st.top() << endl;
    }
    return st.top();
}

// Circular tour
int tour(petrolPump p[], int n)
{
    // Your code here
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

// Sum of Subarray Minimums
int sumSubarrayMins(vector<int> &nums)
{
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;

    for (int i = 0; i < length; ++i)
    {
        while (!stk.empty() && nums[stk.top()] >= nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = stack<int>();

    for (int i = length - 1; i >= 0; --i)
    {
        while (!stk.empty() && nums[stk.top()] > nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    ll sum = 0;

    for (int i = 0; i < length; ++i)
    {
        sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
        sum %= MOD;
    }

    return sum;
}

int main()
{

    return 0;
}