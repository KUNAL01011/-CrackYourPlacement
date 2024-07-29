#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array
int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
            return mid;

        // first be check mid kis range me hai like s to mid  => A
        // else mid+1 => e : B
        if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && nums[mid] >= target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[e] >= target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}



// Minimum Swaps to Sort
int minSwaps(vector<int> &nums)
{
    // Code here
    int n = nums.size();
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        v[i] = {nums[i], i};
    sort(v.begin(), v.end());

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
            continue;
        else
        {
            ++swaps;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return swaps;
}



// Smallest Positive Missing
int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int ci = arr[i] - 1;

        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[ci])
        {
            swap(arr[i], arr[ci]);
            ci = arr[i] - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int main()
{

    return 0;
}