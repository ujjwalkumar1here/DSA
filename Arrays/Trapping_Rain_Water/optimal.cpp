#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left < right)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        if(leftMax < rightMax)
        {
            // here Left side decide the water level means small bar decide
            water += leftMax - height[left];
            left++;
        }
        else
        {
            // Right side decides the water level
            water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};

    cout << "Trapped Water: " << trap(height);

    return 0;
}