#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
        {
            cout << "Target found at index: " << mid << endl;
            return 0;
        }
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "Insert Position = " << left << endl;

    return 0;
}