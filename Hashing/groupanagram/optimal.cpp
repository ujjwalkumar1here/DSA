#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> num;

    for(int i=0;i<strs.size();i++)
    {
        string a = strs[i];
        sort(a.begin(), a.end());

        mp[a].push_back(strs[i]);
    }

    for(auto it : mp)
    {
        num.push_back(it.second);
    }

    for(int i=0;i<num.size();i++)
    {
        for(int j=0;j<num[i].size();j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
}