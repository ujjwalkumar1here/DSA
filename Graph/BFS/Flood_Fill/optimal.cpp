#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int originalColor = image[sr][sc];

    if(originalColor == color)
        return image;

    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int,int>> q;

    q.push({sr, sc});

    vis[sr][sc] = 1;
    image[sr][sc] = color;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 &&
               nr < n && nc < m &&
               image[nr][nc] == originalColor &&
               !vis[nr][nc])
            {
                image[nr][nc] = color;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";

    for(auto row : ans)
    {
        for(auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}