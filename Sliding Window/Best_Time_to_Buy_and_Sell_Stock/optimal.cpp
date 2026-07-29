#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7,1,5,3,6,4};

    int mini = prices[0];
    int maxi = 0;

    for(int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - mini;
        maxi = max(maxi, profit);

        mini = min(mini, prices[i]);
    }

    cout << "Maximum Profit = " << maxi << endl;

    return 0;
}