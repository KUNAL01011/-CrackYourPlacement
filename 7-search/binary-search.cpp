#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int target)
{
  int L = 0, R = arr.size() - 1;

  while (L <= R)
  {
    int mid = L + (R - L) / 2;

    if (target > arr[mid])
    {
      L = mid + 1;
    }
    else if (target < arr[mid])
    {
      R = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}

int main()
{
  return 0;
}