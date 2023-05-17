class Solution
{
public:
    int minDifficulty(vector<int> &jobs, int d)
    {
        int n = jobs.size(), INF = 1e8;
        if (d > n)
            return -1;
        vector<vector<int>> f(n + 1, vector<int>(d + 1, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= d; j++)
            {
                int cost = 0;
                for (int k = i - 1; k >= j - 1; k--)
                { // 原数组第i天存在下标i-1的位置的
                    cost = max(cost, jobs[k]);
                    f[i][j] = min(f[i][j], f[k][j - 1] + cost);
                }
            }
        }
        return f[n][d];
    }
};