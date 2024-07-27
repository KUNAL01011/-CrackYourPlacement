#include <bits/stdc++.h>
using namespace std;

// Permutations in array

static bool comp(int a, int b)
{
    return a > b;
}
bool isPossible(long long a[], long long b[], int n, long long k)
{
    // Your code goes here
    sort(a, a + n);
    sort(b, b + n, comp);

    int i = 0;
    while (i < n)
    {
        if (k > a[i] + b[i])
        {
            return false;
        }
        i++;
    }
    return true;
}


// Find Pair Given Difference
int findPair(int n, int x, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;

        if (x == 0 && mp[arr[i]] > 1)
        {
            return 1;
        }
    }

    if (x == 0)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = x + arr[i];

        if (mp.find(sum) != mp.end())
        {
            return 1;
        }
    }
    return -1;
}

// Ceil The Floor
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    // code here
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return {arr[i], arr[i]};
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= x && i == 0)
        {
            return {-1, arr[i]};
        }
        else if (arr[arr.size() - 1] <= x && i == arr.size() - 1)
        {
            return {arr[i], -1};
        }
        else if (arr[i] < x && arr[i + 1] >= x)
            return {arr[i], arr[i + 1]};
    }
    return {-1, -1};
}

int main()
{

    return 0;
}