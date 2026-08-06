#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find the meeting point
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow != fast);

    // Phase 2: Find the duplicate number
    slow = nums[0];

    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate Number : " << findDuplicate(nums);

    return 0;
}