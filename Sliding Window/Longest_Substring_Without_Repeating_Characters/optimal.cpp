#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";

    vector<int> lastIndex(256, -1);

    int left = 0;
    int right = 0;
    int maxLength = 0;

    while(right < s.size())
    {
        if(lastIndex[s[right]] != -1)
        {
            left = max(left, lastIndex[s[right]] + 1);
        }

        lastIndex[s[right]] = right;

        int length = right - left + 1;
        maxLength = max(maxLength, length);

        right++;
    }

    cout << "Length of Longest Substring = " << maxLength << endl;

    return 0;
}