#include <bits/stdc++.h>
using namespace std;

// 462. Minimum Moves to Equal Array Elements II
int minMoves2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int mid = nums[nums.size() / 2];
    int ans = 0;
    for (auto val : nums)
        ans += abs(mid - val);
    return ans;
}

// 67. Add Binary
string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
            carry += a[i--] - '0';
        if (j >= 0)
            carry += b[j--] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
}

// 628. Maximum Product of Three Numbers
int maximumProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int product;
    int j = nums.size() - 1;

    return max(nums[j] * nums[j - 1] * nums[j - 2], nums[0] * nums[1] * nums[j]);
}

// 168. Excel Sheet Column Title
string convertToTitle(int columnNumber)
{
    string str = "";

    while (columnNumber > 0)
    {
        char ch = char(ceil((columnNumber - 1) % 26 + 65));
        str = ch + str;
        columnNumber = (columnNumber - 1) / 26;
    }
    return str;
}

// Product array puzzle
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    vector<long long int> ans;
    long long int product = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                product *= nums[j];
            }
        }

        ans.push_back(product);
        product = 1;
    }

    return ans;
}

int main()
{

    return 0;
}