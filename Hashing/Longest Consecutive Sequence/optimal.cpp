#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    unordered_set<int> s(nums.begin(), nums.end());

    int maxi = 0;

    for (int num : s)
    {
      
        if (s.find(num - 1) == s.end())
        {
            int current = num;
            int count = 1;

            while (s.find(current + 1) != s.end())
            {
                current++;
                count++;
            }

            maxi = max(maxi, count);
        }
    }

    cout << "Longest Consecutive Sequence Length: " << maxi << endl;

    return 0;
}