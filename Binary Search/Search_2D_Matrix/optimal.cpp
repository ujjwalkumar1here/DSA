#include <bits/stdc++.h>
using namespace std;

int findRow(vector<vector<int>>& matrix, int target)
{
    int left = 0;
    int right = matrix.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(matrix[mid][0] == target)
            return mid;

        else if(matrix[mid][0] > target)
            right = mid - 1;

        else
            left = mid + 1;
    }

    return left - 1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = findRow(matrix, target);

    if(row < 0)
        return false;

    int left = 0;
    int right = matrix[0].size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(matrix[row][mid] == target)
            return true;

        else if(matrix[row][mid] > target)
            right = mid - 1;

        else
            left = mid + 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 16;

    if(searchMatrix(matrix, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}