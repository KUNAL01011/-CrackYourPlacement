#include <bits/stdc++.h>
using namespace std;

// 1 st question
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

// 2 nd question
int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);

        if (nums[index] < 0)
        {
            return index;
        }

        nums[index] *= -1;
    }
    return -1;
}

// 3 rd question
void sortColors(vector<int> &nums)
{
    int i = 0;
    int x = 0;
    int j = nums.size() - 1;
    while (x <= j)
    {
        if (nums[x] == 0)
        {
            swap(nums[x], nums[i]);
            i++;
            x++;
        }
        else if (nums[x] == 2)
        {
            swap(nums[x], nums[j]);
            j--;
        }
        else
        {
            x++;
        }
    }
}

// 4 th question
int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int count = 1;
    for (int j = i + 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            swap(nums[i + 1], nums[j]);
            count++;
            i++;
        }
    }
    return count;
}

// 5 th question
void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

// 6 th question
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

int main()
{

    return 0;
}