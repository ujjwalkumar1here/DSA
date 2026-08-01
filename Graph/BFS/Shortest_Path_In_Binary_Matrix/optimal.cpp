#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();

    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<pair<pair<int,int>, int>> q;

    q.push({{0,0}, 1});
    visited[0][0] = true;

    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;

        q.pop();

        if(row == n-1 && col == n-1)
            return dist;

        for(int i = 0; i < 8; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == 0 &&
               !visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({{nr,nc}, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> grid =
    {
        {0,1},
        {1,0}
    };

    cout << "Shortest Path Length: "
         << shortestPathBinaryMatrix(grid);

    return 0;
}