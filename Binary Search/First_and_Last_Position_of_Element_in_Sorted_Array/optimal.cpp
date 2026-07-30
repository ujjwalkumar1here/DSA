#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
        {
            ans = mid;
            right = mid - 1;
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

    return ans;
}

int lastOccurrence(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
        {
            ans = mid;
            left = mid + 1;
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

    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);

    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;

    return 0;
}