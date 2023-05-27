class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = 1;
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 0 && dist[a][b] == -1)
                {
                    dist[a][b] = dist[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};