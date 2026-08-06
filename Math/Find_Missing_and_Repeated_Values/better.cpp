#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
{
    int n = grid.size();

    set<int> s;

    int repeated = -1;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s.find(grid[i][j]) != s.end())
            {
                repeated = grid[i][j];
            }

            sum += grid[i][j];
            s.insert(grid[i][j]);
        }
    }

    int N = n * n;

    int expectedSum = N * (N + 1) / 2;

    int missing = expectedSum - (sum - repeated);

    return {repeated, missing};
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    vector<int> ans = findMissingAndRepeatedValues(grid);

    cout << "Repeated : " << ans[0] << endl;
    cout << "Missing  : " << ans[1] << endl;

    return 0;
}