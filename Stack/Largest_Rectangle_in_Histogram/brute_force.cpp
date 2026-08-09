#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();

    int maxarea = 0;

    for(int i = 0; i < n; i++)
    {
        int mh = INT_MAX;

        for(int j = i; j < n; j++)
        {
            // Minimum height in the current range from [i...j]
            mh = min(mh, heights[j]);

            int width = j - i + 1;

            int area = mh * width;

            maxarea = max(maxarea, area);
        }
    }

    return maxarea;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};

    cout << "Largest Rectangle Area: "
         << largestRectangleArea(heights);

    return 0;
}