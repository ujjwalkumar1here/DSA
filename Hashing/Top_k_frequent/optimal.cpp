#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    unordered_map<int,int> mp;
    vector<int> result;

  
    for(int num : nums)
    {
        mp[num]++;
    }

    
    vector<pair<int,int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(),
        [](pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        });

    for(int i = 0; i < k; i++)
    {
        result.push_back(v[i].first);
    }

   
    for(int num : result)
    {
        cout << num << " ";
    }

    return 0;
}