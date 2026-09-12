#include <bits/stdc++.h>
using namespace std;

// But the problem is worst case complexity could be O(n^2)
void in_place_merge(vector<int> &arr, int s, int m, int e)
{
  int i = s;
  int j = m + 1;

  while (i <= m && j <= e)
  {
    if (arr[i] <= arr[j])
    {
      i++;
    }
    else
    {
      // arr[j] belongs before arr[i]
      int value = arr[j];

      // Shift everything from i to j-1 one position right
      int k = j;

      while (k > i)
      {
        arr[k] = arr[k - 1];
        k--;
      }

      arr[i] = value;

      // Both boundaries move
      i++;
      m++;
      j++;
    }
  }
}

// O(n)
void merge(vector<int> &arr, int start, int mid, int end)
{
  vector<int> L = {arr.begin() + start, arr.begin() + mid + 1};
  vector<int> R = {arr.begin() + mid + 1, arr.begin() + end + 1};

  int i = 0;
  int j = 0;
  int k = start;

  while (i < L.size() && j < R.size())
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i++];
    }
    else
    {
      arr[k] = R[j++];
    }
    k++;
  }

  while (i < L.size())
  {
    arr[k++] = L[i++];
  }
  while (j < R.size())
  {
    arr[k++] = R[j++];
  }
}

vector<int> merge_sort(vector<int> &arr, int start, int end)
{
  if (end - start + 1 <= 1)
  {
    return arr;
  }

  int mid = (start + end) / 2;

  merge_sort(arr, start, mid);
  merge_sort(arr, mid + 1, end);
  merge(arr, start, mid, end);
  return arr;
}

int main()
{

  return 0;
}