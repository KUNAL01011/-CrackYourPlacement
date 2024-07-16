#include <bits/stdc++.h>
using namespace std;

// 974. Subarray Sums Divisible by K
int subarraysDivByK(vector<int> &nums, int k)
{
    int count = 0;
    int prefixSum = 0;
    std::unordered_map<int, int> prefixMap;
    prefixMap[0] = 1;

    for (int num : nums)
    {
        prefixSum += num;
        int mod = prefixSum % k;
        if (mod < 0)
        {
            mod += k;
        }

        if (prefixMap.find(mod) != prefixMap.end())
        {
            count += prefixMap[mod];
            prefixMap[mod] += 1;
        }
        else
        {
            prefixMap[mod] = 1;
        }
    }

    return count;
}

// 1. Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(prices[i], minPrice);

        profit = max(profit, prices[i] - minPrice);
    }
    return profit;
}

// Chocolate Distribution Problem

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    sort(a.begin(), a.end());

    int i = 0;
    int j = m - 1;

    long long diff = a[j] - a[i];
    j++;
    i++;
    while (j < n)
    {
        diff = min(diff, a[j] - a[i]);
        j++;
        i++;
    }

    return diff;
}

int main()
{

    return 0;
}