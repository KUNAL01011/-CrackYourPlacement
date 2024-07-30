#include <bits/stdc++.h>
using namespace std;

// AGGRCOW

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int cntCows = 1;
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

// Count of Smaller Numbers After Self
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans, cnt(n, 0);
    ans.push_back(nums[n - 1]);
    cnt[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);

            cnt[i] = ans.size() - 1;
        }
        else
        {
            int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ;
            ans.insert(ans.begin() + ind, nums[i]);

            cnt[i] = ind;
        }
    }
    return cnt;
}

// Split Array Largest Sum

int countStudents(vector<int> arr, int page)
{
    int n = arr.size();
    int students = 1;
    long long pageStudent = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageStudent + arr[i] <= page)
        {
            pageStudent += arr[i];
        }
        else
        {
            students++;
            pageStudent = arr[i];
        }
    }
    return students;
}

int bookAllocationBinary(vector<int> arr, int n, int m)
{
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int splitArray(vector<int> &nums, int k)
{
    return bookAllocationBinary(nums, nums.size(), k);
}

int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k = 4;

    cout << aggressiveCows(arr, k) << endl;
    return 0;
}