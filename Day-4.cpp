#include <bits/stdc++.h>
using namespace std;

// 560. Subarray Sum Equals K
int subarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;
    mp[0] = 1;
    int preSum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int remove = preSum - k;
        count += mp[remove];
        mp[preSum] += 1;
    }
    return count;
}

// 54. Spiral Matrix
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    int count = 0;
    int totalCount = row * col;

    while (count < totalCount)
    {
        for (int i = startingCol; count < totalCount && i <= endingCol; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        for (int i = startingRow; count < totalCount && i <= endingRow; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for (int i = endingCol; count < totalCount && i >= startingCol; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for (int i = endingRow; count < totalCount && i >= startingRow; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

// 79. Word Search
bool find(vector<vector<char>> &board, vector<vector<int>> &visited,
          string &word, vector<pair<int, int>> &dirc, int row, int col,
          int idx)
{
    if (idx == word.size())
        return true;
    if (row < 0 || row >= board.size() || col < 0 ||
        col >= board[0].size() || visited[row][col] ||
        board[row][col] != word[idx])
    {
        return false;
    }

    visited[row][col] = 1;
    for (auto &d : dirc)
    {
        int newRow = row + d.first;
        int newCol = col + d.second;
        if (find(board, visited, word, dirc, newRow, newCol, idx + 1))
        {
            return true;
        }
    }
    visited[row][col] = 0;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(
        n, vector<int>(m, 0));
    vector<pair<int, int>> dirc = {
        {1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == word[0] &&
                find(board, visited, word, dirc, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

// 88. Merge Sorted Array
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}


// 55. Jump Game
bool canJump(vector<int> &nums)
{
    int targetNumIndex = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (targetNumIndex <= i + nums[i])
        {
            targetNumIndex = i;
        }
    }
    return targetNumIndex == 0;
}
int main()
{

    return 0;
}