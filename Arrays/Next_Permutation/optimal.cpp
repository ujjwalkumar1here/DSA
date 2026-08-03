#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();

    int pivot = -1;

    // Step 1: Find the pivot
    for(int i = n - 2; i >= 0; i--)
    {
        if(nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // Step 2: Find the next greater element and swap
    if(pivot != -1)
    {
        for(int i = n - 1; i > pivot; i--)
        {
            if(nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
    }

    // Step 3: Reverse the suffix
    reverse(nums.begin() + pivot + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 5, 4};

    nextPermutation(nums);

    cout << "Next Permutation : ";

    for(int x : nums)
        cout << x << " ";

    return 0;
}
