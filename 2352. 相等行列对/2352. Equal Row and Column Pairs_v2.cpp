class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        const int n = grid.size();

        map<vector<int>, int> hash;

        // 将每一行存入哈希表
        for (auto &g : grid)
            hash[g]++;

        int cnt = 0;
        vector<int> tmp;
        // 查询每一行是否出现过
        for (int i = 0; i < n; i++)
        {
            tmp.clear();
            for (int j = 0; j < n; j++)
            {
                tmp.push_back(grid[j][i]);
            }
            if (hash.find(tmp) != hash.end())
                cnt += hash[tmp];
        }
        return cnt;
    }
};