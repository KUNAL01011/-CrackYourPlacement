#include <bits/stdc++.h>
using namespace std;

// 169. Majority Element

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
            cnt++;
        else
        {
            cnt--;
        }
    }

    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
            cnt2++;
    }

    if (cnt2 > n / 2)
    {
        return el;
    }
    return -1;
}

// 493. Reverse Pairs
int c = 0;
int revPairs(vector<int> &a, vector<int> &b)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        long long int bruh = b[j];
        if (a[i] > 2 * bruh)
        {
            count += a.size() - i;
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
    }
    if (i == a.size())
        while (j < b.size())
            res[k++] = b[j++];
    else if (j == b.size())
        while (i < a.size())
            res[k++] = a[i++];
}
void mergeSort(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++)
        a[i] = v[i];
    for (int i = 0; i < n2; i++)
        b[i] = v[i + n1];

    mergeSort(a);
    mergeSort(b);

    c += revPairs(a, b);

    merge(a, b, v);
    a.clear();
    b.clear();
}
int reversePairs(vector<int> &nums)
{
    mergeSort(nums);
    return c;
}

// All Unique Permutations of an array

vector<vector<int>> uniquePerms(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    ans.push_back(arr);
    while (next_permutation(arr.begin(), arr.end()))
    {
        ans.push_back(arr);
    }
    return ans;
}

// 289. Game of Life
void gameOfLife(vector<vector<int>> &board)
{

    int n = board.size();
    int m = board[0].size();
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            int count = 0;
            for (int c = a - 1; c <= a + 1; ++c)
            {
                for (int d = b - 1; d <= b + 1; ++d)
                {
                    if (c == a && d == b)
                        continue;
                    if (c >= 0 && c < n && d >= 0 && d < m && (board[c][d] == 1 || board[c][d] == 3))
                    {
                        count++;
                    }
                }
            }

            if (board[a][b] == 1 && (count < 2 || count > 3))
            {
                board[a][b] = 3;
            }
            if (board[a][b] == 0 && count == 3)
            {
                board[a][b] = 2;
            }
        }
    }
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < m; ++b)
        {
            if (board[a][b] == 3)
            {
                board[a][b] = 0;
            }
            if (board[a][b] == 2)
            {
                board[a][b] = 1;
            }
        }
    }
}
int main()
{

    return 0;
}