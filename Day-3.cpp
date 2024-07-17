#include <bits/stdc++.h>
using namespace std;

// 1423. Maximum Points You Can Obtain from Cards
int maxScore(vector<int> &cardPoints, int k)
{
    int i = 0;
    int j = 0;
    int currSum = 0;
    int totalSum = 0;
    int ans = 0;
    for (auto i : cardPoints)
        totalSum += i;
    if (k == cardPoints.size())
        return totalSum;

    while (j < cardPoints.size())
    {
        currSum += cardPoints[j];
        if (j - i + 1 < cardPoints.size() - k)
        {
            j++;
        }
        else
        {
            ans = max(ans, totalSum - currSum);
            currSum -= cardPoints[i];
            i++;
            j++;
        }
    }

    return ans;
}

// 18. 4Sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {

        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        for (int x = i + 1; x < nums.size(); x++)
        {

            if (x != i + 1 && nums[x] == nums[x - 1])
                continue;

            int j = x + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                long long sum = nums[i];
                sum += nums[x];
                sum += nums[j];
                sum += nums[k];

                if (sum < target)
                {
                    j++;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {

                    vector<int> temp = {nums[i], nums[x], nums[j], nums[k]};
                    ans.push_back(temp);
                    k--;
                    j++;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
    }

    return ans;
}

// 15. 3Sum
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {

        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                k--;
                j++;

                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    return ans;
}

// 11. Container With Most Water
int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    long long maxWater = INT_MIN;

    while (i < j)
    {
        int firstIndex = (height[i] > height[j]) ? height[j] : height[i];

        int secondIndex = j - i;
        int ans = (firstIndex * secondIndex);
        maxWater = maxWater > ans ? maxWater : ans;

        if (height[i] > height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return maxWater;
}
// 442. Find All Duplicates in an Array
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);

        if (nums[index - 1] < 0)
        {
            ans.push_back(index);
        }

        nums[index - 1] = nums[index - 1] * -1;
    }
    return ans;
}
int main()
{

    return 0;
}