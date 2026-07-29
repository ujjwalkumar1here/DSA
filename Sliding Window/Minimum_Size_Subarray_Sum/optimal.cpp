#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int left = 0;
    int sum = 0;
    int mini = INT_MAX;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum >= target)
        {
            mini = min(mini, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    if(mini == INT_MAX)
        cout << 0;
    else
        cout << "Minimum Length = " << mini;

    return 0;
}