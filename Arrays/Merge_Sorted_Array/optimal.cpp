#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int left1 = m - 1;
    int left2 = n - 1;
    int index = m + n - 1;

    while(left1 >= 0 && left2 >= 0)
    {
        if(nums1[left1] >= nums2[left2])
        {
            nums1[index] = nums1[left1];
            left1--;
        }
        else
        {
            nums1[index] = nums2[left2];
            left2--;
        }

        index--;
    }

    while(left2 >= 0)
    {
        nums1[index] = nums2[left2];
        left2--;
        index--;
    }
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array : ";

    for(int x : nums1)
    {
        cout << x << " ";
    }

    return 0;
}