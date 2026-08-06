#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    vector<int> ans;

    int left1 = 0;
    int left2 = 0;

    while(left1 < m && left2 < n)
    {
        if(nums1[left1] <= nums2[left2])
        {
            ans.push_back(nums1[left1]);
            left1++;
        }
        else
        {
            ans.push_back(nums2[left2]);
            left2++;
        }
    }

    while(left1 < m)
    {
        ans.push_back(nums1[left1]);
        left1++;
    }

    while(left2 < n)
    {
        ans.push_back(nums2[left2]);
        left2++;
    }

    nums1 = ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";

    for(int x : nums1)
    {
        cout << x << " ";
    }

    return 0;
}