#include <bits/stdc++.h>
using namespace std;

// Allocate Minimum Pages
bool isValid(long mid, int arr[], int k, int n)
{
    int a = 0;
    long cs = 0;
    int i = 0;
    while (i < n)
    {
        cs += arr[i];
        if (cs > mid)
        {
            cs = arr[i];
            a++;
        }
        i++;
    }
    return a >= k;
}

long long findPages(int n, int arr[], int m)
{
    long long sum = 0;
    long max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    if (n == m)
        return max;
    if (m > n)
        return -1;
    long long s = max, e = sum;
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        if (isValid(mid, arr, m, n))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}



// Make all array elements equal with minimum cost
int minCostToMakeElementEqual(int a[], int n)
{

    int y;
    if (n % 2 == 1)
        y = a[n / 2];

    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;

    int s = 0;
    for (int i = 0; i < n; i++)
        s += abs(a[i] - y);

    return s;
}


// Redix sort
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{

    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Check if reversing a sub array make the array sorted
bool checkReverse(int arr[], int n)
{
    
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

   
    sort(temp, temp + n);

    
    int front;
    for (front = 0; front < n; front++)
        if (temp[front] != arr[front])
            break;

  
    int back;
    for (back = n - 1; back >= 0; back--)
        if (temp[back] != arr[back])
            break;

    
    if (front >= back)
        return true;

   
    do
    {
        front++;
        if (arr[front - 1] < arr[front])
            return false;
    } while (front != back);

    return true;
}

int main()
{

    return 0;
}