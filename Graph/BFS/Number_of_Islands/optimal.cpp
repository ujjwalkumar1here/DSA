#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<char>>& grid,
         vector<vector<int>>& vis)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 &&
                nr < n && nc < m &&
                !vis[nr][nc] &&
                grid[nr][nc] == '1')
            {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                count++;
                bfs(i, j, grid, vis);
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands : " << numIslands(grid);

    return 0;
}