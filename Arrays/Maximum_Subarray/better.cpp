#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int n = nums.size();

    int maxi = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += nums[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum : " << maxSubArray(nums);

    return 0;
}