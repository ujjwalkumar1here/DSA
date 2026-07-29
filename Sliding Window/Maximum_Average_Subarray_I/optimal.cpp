#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double sum = 0;


    for(int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    double maxi = sum;

    
    for(int i = k; i < nums.size(); i++)
    {
        sum = sum - nums[i - k] + nums[i];
        maxi = max(maxi, sum);
    }

    cout << "Maximum Average = " << maxi / k << endl;

    return 0;
}