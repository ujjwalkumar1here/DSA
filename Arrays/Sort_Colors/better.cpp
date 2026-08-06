#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
            count0++;
        else if(nums[i] == 1)
            count1++;
        else
            count2++;
    }

    int i = 0;

    while(count0 > 0)
    {
        nums[i++] = 0;
        count0--;
    }

    while(count1 > 0)
    {
        nums[i++] = 1;
        count1--;
    }

    while(count2 > 0)
    {
        nums[i++] = 2;
        count2--;
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    cout << "Sorted Array : ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}