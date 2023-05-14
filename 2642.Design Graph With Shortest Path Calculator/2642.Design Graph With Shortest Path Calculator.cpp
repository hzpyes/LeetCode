class Graph
{
    int n;
    int dp[100][100];

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = INT_MAX / 3; // 避免后面add方法的加法越界，所以除以3

        for (int i = 0; i < n; i++)
            dp[i][i] = 0; // 初始化自己到自己为0

        for (auto &edge : edges)
            dp[edge[0]][edge[1]] = edge[2];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    void addEdge(vector<int> edge)
    {
        int a = edge[0], b = edge[1], d = edge[2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][a] + d + dp[b][j]);
    }

    int shortestPath(int node1, int node2)
    {
        return dp[node1][node2] == INT_MAX / 3 ? -1 : dp[node1][node2];
    }
};