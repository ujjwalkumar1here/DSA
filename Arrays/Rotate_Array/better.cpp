#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();

    k = k % n;

    int a = n - k;

    vector<int> ans;

    // Take the last k elements
    for(int i = a; i < n; i++)
    {
        ans.push_back(nums[i]);
    }

    // Take the remaining elements
    for(int i = 0; i < a; i++)
    {
        ans.push_back(nums[i]);
    }

    // Copy answer back to nums
    nums = ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}