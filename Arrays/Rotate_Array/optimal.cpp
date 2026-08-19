#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();

    k = k % n;

    // Reverse first n-k elements
    reverse(nums.begin(), nums.begin() + n - k);

    // Reverse last k elements
    reverse(nums.begin() + n - k, nums.end());

    // Reverse the entire array
    reverse(nums.begin(), nums.end());
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