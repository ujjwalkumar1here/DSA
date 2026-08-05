#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int currSum = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];

        maxi = max(maxi, currSum);

        if(currSum < 0)
        {
            currSum = 0;
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